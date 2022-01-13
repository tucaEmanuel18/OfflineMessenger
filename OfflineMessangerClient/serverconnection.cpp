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
    _log_out();
    _quit();
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

vector<Conversation*> ServerConnection::_get_conv(){
    json response = this->send_request(command_builder._get_conv(this->me.auth).dump());
    if(response["status"] == 200){
        vector<Conversation*> conversations;
        json j_conversations = response["conversations"];
        for(unsigned long i=0; i < j_conversations.size(); i++){
            string id_room = remove_quotes(j_conversations.at(i).at("id_room").dump()).c_str();
            string id_user = remove_quotes(j_conversations.at(i).at("id_user").dump()).c_str();
            string username = remove_quotes(j_conversations.at(i).at("username").dump()).c_str();
            string connected = remove_quotes(j_conversations.at(i).at("connected").dump()).c_str();
            Conversation* new_conversation = new Conversation(id_room, id_user, username, connected);
            conversations.push_back(new_conversation);
        }
        return conversations;
    }
}

vector<Message*> ServerConnection::_get_messages(string id_room){
    json response = this->send_request(command_builder._get_messages(this->me.auth, id_room).dump());
    if(response["status"] == 200){
        vector<Message*> messages;
        json j_message = response["messages"];
        for(unsigned long i=0; i < j_message.size(); i++){
            string id_message = remove_quotes(j_message.at(i).at("id_message").dump()).c_str();
            string id_sender = remove_quotes(j_message.at(i).at("id_sender").dump()).c_str();
            string id_room = remove_quotes(j_message.at(i).at("id_room").dump()).c_str();
            string content = remove_quotes(j_message.at(i).at("content").dump()).c_str();
            string time = remove_quotes(j_message.at(i).at("time").dump()).c_str();
            string reply_to = remove_quotes(j_message.at(i).at("reply_to").dump()).c_str();
            Message* message = new Message(id_message, id_sender, id_room, content, time);
            if(reply_to.compare("NULL") != 0){
                string reply_sender = remove_quotes(j_message.at(i).at("reply_sender").dump()).c_str();
                string reply_content = remove_quotes(j_message.at(i).at("reply_content").dump()).c_str();
                string reply_time = remove_quotes(j_message.at(i).at("reply_time").dump()).c_str();
                message->setReplyToMessage(reply_to, reply_sender, reply_content, reply_time);
            }
            messages.push_back(message);
        }
        return messages;
    }else{
        if(response["status"] >= 500){
            throw std::domain_error(response["message"]);
        }else {
            throw std::invalid_argument(response["message"]);
        }
    }
}

void ServerConnection::_send_message(string id_room, string content, string reply_to){
    json response = this->send_request(command_builder._send_message(this->me.auth, id_room, content, reply_to).dump());

    if(response["status"] >= 500){
        throw std::domain_error(response["message"]);
    }else if(response["status"] >= 400){
        throw std::invalid_argument(response["message"]);
    }
}

void ServerConnection::_send_message(string id_room, string content){
    json response;
    if(selectedMessageId.empty()){
        response = this->send_request(command_builder._send_message(this->me.auth, id_room, content).dump());
    }else{
        response = this->send_request(command_builder._send_message(this->me.auth, id_room, content, selectedMessageId).dump());
    }

    if(response["status"] >= 500){
        throw std::domain_error(response["message"]);
    }else if(response["status"] >= 400){
        throw std::invalid_argument(response["message"]);
    }
}

void ServerConnection::_create_conv(string friend_username){
    if(friend_username.compare(me.username) == 0){
        throw std::invalid_argument("This is your username! You can't create a conersation with you!");
    }
    json response = this->send_request(command_builder._create_conv(this->me.auth, friend_username).dump());

    if(response["status"] >= 500){
        throw std::domain_error(response["message"]);
    }else if(response["status"] >= 400){
        throw std::invalid_argument(response["message"]);
    }
}

void ServerConnection::_log_out(){
    if(this->me.isSet()){
        json response = this->send_request(command_builder._log_out(this->me.auth).dump());
        if(response["status"] >= 500){
            throw std::domain_error(response["message"]);
        }else if(response["status"] >= 400){
            throw std::invalid_argument(response["message"]);
        }
    }
}

void ServerConnection::_quit(){
    this->send_request(command_builder._quit().dump());
}


string ServerConnection::remove_quotes(string quoted){
    return quoted.substr(1, quoted.length() - 2);
}
