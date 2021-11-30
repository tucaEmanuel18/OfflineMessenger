#pragma once
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string>
#include <thread>
#include <pthread.h>
#include <TCPScanner.h>

class ChatServer
{
protected:
	unsigned int port;
	unsigned int backlog;
	struct sockaddr_in server_socket;
	struct sockaddr_in client_socket;
	int socket_descriptor;
	void create_client_thread(int client_file_descriptor);
	
	void handle_connection_thread(int client_file_descriptor);

public:
	ChatServer(unsigned int port, unsigned int backlog);
	~ChatServer();
	static TCPScanner scanner;
	static void handle_connection(int client_file_descriptor);
	void start();
};

