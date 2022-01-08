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
		printf("Error at connect()\n");
		exit(-1);
	}
	
	scanner.set_socket_descriptor(socket_descriptor);
	handle_connection();
}

void ChatClient::handle_connection(){
		bool quit = false;
		string command;
		while (!quit){
			
			// getting the client command
			printf("[Client] Get a command: ");
			fflush(stdout);
			getline (cin, command);
			
			string message = prepare_json(command);
			if(message.empty()){
				continue;
			}
			
			//Sending the message to the server
			printf("[LOG] I'm sending to the server the following message = %s\n", message.c_str());
			try{
				scanner.Write(message);
			}catch(ios_base::failure const& e){
					printf("[Client Error] %s\n", e.what());
					break;
			}
			
			if(strcmp(command.c_str(), "quit") == 0){
				// closing the connection
				close(socket_descriptor);
				quit = true;
			}else{
				// Receiving the message from the server
				string received_message;
				try{
					received_message = scanner.Read();
				}catch(ios_base::failure const& e){
					printf("[Client Error] %s\n", e.what());
					break;
				}
				// printing the received message
				printf("[LOG] The following message was received: %s\n", received_message.c_str());
			}
		}
	}


string ChatClient::prepare_json(string command){
	json json_message;
	json_message["command"] = command.c_str();
	
	if(command.compare("register") == 0){
		string username;
		string password; 
		
		printf("[Client] Get username: ");
		fflush(stdout);
		getline (cin, username);
		
		printf("[Client] Get password: ");
		fflush(stdout);
		getline (cin, password);
		
		json_message["username"] = username.c_str();
		json_message["password"] = password.c_str();
	}else if(command.compare("log") == 0){
		string username;
		string password; 
		
		printf("[Client] Get username: ");
		fflush(stdout);
		getline (cin, username);
		
		printf("[Client] Get password: ");
		fflush(stdout);
		getline (cin, password);
		
		json_message["username"] = username.c_str();
		json_message["password"] = password.c_str();
		
	}else if(command.compare("create_conv") == 0){
		string auth;
		string friend_username; 
		
		printf("[Client] Get your id: ");
		fflush(stdout);
		getline (cin, auth);
		
		printf("[Client] Get friend_username: ");
		fflush(stdout);
		getline (cin, friend_username);
		
		json_message["auth"] = auth.c_str();
		json_message["friend_username"] = friend_username.c_str();
	}else if(command.compare("get_conv") == 0){
		string auth;
		
		printf("[Client] Get your id: ");
		fflush(stdout);
		getline (cin, auth);
		
		json_message["auth"] = auth.c_str();
	}else if(command.compare("create_msg") == 0){
		string auth;
		string id_room;
		string content;
		
		printf("[Client] Get your id: ");
		fflush(stdout);
		getline (cin, auth);
		
		printf("[Client] Get id_room: ");
		fflush(stdout);
		getline (cin, id_room);
		
		printf("[Client] Get content ");
		fflush(stdout);
		getline (cin, content);
		
		json_message["auth"] = auth.c_str();
		json_message["id_room"] = id_room.c_str();
		json_message["content"] = content.c_str();
	}else if(command.compare("get_msg") == 0){
		string auth;
		string id_room;
		
		printf("[Client] Get your id: ");
		fflush(stdout);
		getline (cin, auth);
		
		printf("[Client] Get id_room: ");
		fflush(stdout);
		getline (cin, id_room);
		
		json_message["auth"] = auth.c_str();
		json_message["id_room"] = id_room.c_str();
	}else{
		printf("This command is unknown...\n");
		return "";
	}
	return json_message.dump();
}