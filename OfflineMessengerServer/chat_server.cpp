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
        printf("%s Waiting the message ... \n", prefix.c_str());
        fflush(stdout);

        string msg = scanner.Read();
        printf("%s The received message: %s\n", prefix.c_str(), msg.c_str());
        if(msg.compare("quit") == 0){
            // close the connection
            close(client);
            break;
        }

        //prepare the response message
        string msg_rasp = "Hello " + msg;
        scanner.Write(msg_rasp);
        printf("%s The following message was send: %s\n", prefix.c_str(), msg_rasp.c_str());
    }
}