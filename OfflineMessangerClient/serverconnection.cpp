#include "serverconnection.h"

ServerConnection::ServerConnection(string addres, unsigned int port)
{
    this->address = addres;
    this->port = port;
    this->scanner = TCPScanner();
    this->command_builder = CommandBuilder();
    this->me = User();
}

ServerConnection::ServerConnection(const ServerConnection &server_connection){
    this->address = server_connection.address;
    this->port = server_connection.port;
    this->command_builder = server_connection.command_builder;
    this->me = server_connection.me;
    this->scanner = server_connection.scanner;
}

User ServerConnection::get_logged_user(){
    return this->me;
}

int ServerConnection::run()
{
    // creating a new socket
    if((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        return errno;
    }

    // set created socket in scanner object
    scanner.set_socket_descriptor(socket_descriptor);

    // preparing data structures
    client_socket.sin_family = AF_INET;
    client_socket.sin_addr.s_addr = inet_addr(address.c_str());
    client_socket.sin_port = htons(port);

    // connecting to the server
    return connect(socket_descriptor, (struct sockaddr *) &client_socket, sizeof(struct sockaddr)) == -1 ? errno: 0;
}


int ServerConnection::stop(){
    return close(socket_descriptor) == -1 ? errno : 0;
}

json ServerConnection::send_request(string command){
    printf("[LOG] ServerConnection::send_request -> %s\n", command.c_str());
    fflush(stdout);
    json response;
    try{
        scanner.Write(command);
    }catch(ios_base::failure const& e){
        response = {
            {"status", 500},
            {"message", "Error on client when sending the request!"}
        };
    }

    try{
        string response_str = scanner.Read();
        response = json::parse(response_str);
    }catch(ios_base::failure const& e){
        response = {
            {"status", 500},
            {"message", "Error on client when receiving the response!"}
        };
    }

    return response;
}

json ServerConnection::_register(string username, string password){
    return this->send_request(command_builder._register(username, password).dump());
}


json ServerConnection::_log(string username, string password){
    json response = this->send_request(command_builder._log(username, password).dump());
    if(response.at("status") == 200){
        this->me = User(response.at("user").at("username"), response.at("user").at("id_user"), response.at("user").at("connected"));
    }
    return response;
}

json ServerConnection::_get_conv(){
    return this->send_request(command_builder._get_conv(this->me.auth).dump());
}
