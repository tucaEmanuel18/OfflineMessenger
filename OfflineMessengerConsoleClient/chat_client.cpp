#include "chat_client.h"

ChatClient::ChatClient(const char* address, unsigned int port)
{
	this->address = address; 
	this->port = port;
	this->scanner = TCPScanner();
}

ChatClient::~ChatClient()
{
}

void ChatClient::run(){
	// creating a new socket
    if((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("Error at socket()!");
		exit(-1);
	} 
    
    // preparing data structures
    client_socket.sin_family = AF_INET;
    client_socket.sin_addr.s_addr = inet_addr(address);
    client_socket.sin_port = htons(port);

    // connecting to the server
    if(connect(socket_descriptor, (struct sockaddr *) &client_socket, sizeof(struct sockaddr)) < 0){
		printf("Error at connect()");
		exit(-1);
	}
	
	scanner.set_socket_descriptor(socket_descriptor);
	handle_connection();
}

void ChatClient::handle_connection(){
		char message[BUFFER_SIZE];
		bool quit = false;
		while (!quit){
			// getting the client message
			bzero(message, BUFFER_SIZE);
			
			printf("[Client] Get a command: ");
			fflush(stdout);

			int size = read(0, message, BUFFER_SIZE);
			message[size - 1] = '\0';
			
			//Sending the message to the server
			printf("[Client] I will send to the server the following message: %s\n", message);
			scanner.Write(message);

			if(strcmp(message, "quit") == 0){
				// closing the connection
				close(socket_descriptor);
				quit = true;
			}else{
				// Receiving the message from the server
				string received_message = scanner.Read();
				// printing the received message
				printf("[Client] The following message was received: %s\n", received_message.c_str());
			}
		}
	}
