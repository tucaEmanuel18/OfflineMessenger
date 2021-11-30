#pragma once
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string>
#include <cstring>
#include "TCPScanner.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif

using namespace std;

class ChatClient
{
private:
	unsigned int port;
	const char* address;
	int socket_descriptor; 
    struct sockaddr_in client_socket;
	void handle_connection();
	TCPScanner scanner;
public:
	ChatClient(const char* address, unsigned int port);
	~ChatClient();
	void run();
	
};

