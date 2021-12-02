#include "chat_server.h"

using namespace std;

ChatServer::ChatServer(unsigned int port, unsigned int backlog = 5)
{
	this->port = port;
	this->backlog = backlog;
}

ChatServer::~ChatServer()
{
}

TCPScanner ChatServer::scanner = TCPScanner();
CommandRouter ChatServer::command_router = CommandRouter();


void ChatServer::start()
{
	// create a new socket
	if((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("[Server]: Error at socket()");
		exit(-1);
	}
	
	// set on the SO_REUSEADDR option
	int on = 1;
    setsockopt(socket_descriptor, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

	// preparing data structures
	bzero(&server_socket, sizeof(server_socket));
    bzero(&client_socket, sizeof(client_socket));

    server_socket.sin_family = AF_INET;
    server_socket.sin_addr.s_addr = htonl(INADDR_ANY);
    server_socket.sin_port = htons(port);
	
	// binding the socket with the address
	if(bind(socket_descriptor, (struct sockaddr *) &server_socket, sizeof(struct sockaddr)) < 0){
		printf("[Server] - Error at bind()");
		exit(-1);
	}
	
	if(listen(socket_descriptor, backlog) < 0){
		printf("[Server] - Error at listen()");
		exit(-1);
	}
	
	while(1){
		unsigned int client;
        unsigned int length = sizeof(client_socket);

        printf("[Server] Listening at port: %d!\n", port);
        fflush(stdout);

        // accept a client
        if((client = accept(socket_descriptor, (struct sockaddr * ) &client_socket, &length)) < 0){
			printf("[Server] Error at accept()");
		} 
            
        printf("[Server] Client with fd %d was connected\n", client);
        this->scanner.set_socket_descriptor(client);
        // create a new thread for this new client
		new thread(handle_connection, client);

	}
}

void ChatServer::handle_connection(int client){
    string prefix = "[Server -> Client " + to_string(client) + "]";

    while(1){
        printf("%s Waiting a command from client ... \n", prefix.c_str());
        fflush(stdout);
		//Read comand from client
        string command_request;
		try{
			command_request = scanner.Read();
		}catch(std::ios_base::failure const& e){
			printf("%s Error at Read() - %s\n", prefix.c_str(), e.what());
			break;
		}
		
        printf("%s The received command: %s\n", prefix.c_str(), command_request.c_str());
		
		// Process request
		json json_command = json::parse(command_request);
		printf("json_command = %s\n", json_command.dump().c_str());
		ICommand* command = command_router.route(json_command);
		
		json response;
		if(command == nullptr){
			response = {
				{"status", 405},
				{"message", "Command not allowed!"}
			};
		}else{
			response = command->execute();
		}
		
        //Sending the response
        try{
			scanner.Write(response.dump());
			printf("%s The following message was send: %s\n", prefix.c_str(), response.dump().c_str());
		}catch(std::ios_base::failure const& e){
			printf("%s Error at Write() - %s\n", prefix.c_str(), e.what());
			break;
		}
    }
}