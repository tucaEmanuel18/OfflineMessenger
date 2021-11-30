#include "TCPScanner.h"
#include <unistd.h>
#include <strings.h>

TCPScanner::TCPScanner()
{
	this->socket_descriptor = 0;
}

TCPScanner::~TCPScanner()
{
	delete[] buffer;
}


void TCPScanner::Write(string message){
	unsigned int length = message.size();

	if(write(socket_descriptor, &length, sizeof(unsigned int)) <= 0){
		printf("Error at writing message length to descriptor %d\n", socket_descriptor);
		throw std::ios_base::failure("");
	}
	
	if(write(socket_descriptor, message.c_str(), message.size()) <= 0){
		printf("Error at writing message to descriptor %d\n", socket_descriptor);
		throw std::ios_base::failure("");
	}
}


string TCPScanner::Read(){
	bzero(buffer, BUFFER_SIZE);
	unsigned int length = 0;

	if(read(socket_descriptor, &length, sizeof(unsigned int)) <= 0){
		printf("Error at reading message length from descriptor %d\n", socket_descriptor);
		throw std::ios_base::failure("");
	}

	string message = "";
	unsigned int read_bytes = 0;
	while(read_bytes < length){
		int current_bytes = read(socket_descriptor, buffer, min(BUFFER_SIZE - 1, length - read_bytes));
		if(current_bytes <= 0){
			printf("Error at reading message from descriptor %d\n", socket_descriptor);
			throw std::ios_base::failure("");
		}
		buffer[current_bytes] = '\0';

		message.append(buffer);
		read_bytes += current_bytes;
	}
	return message;
}

void TCPScanner::set_socket_descriptor(unsigned int socket_descriptor){
	this->socket_descriptor = socket_descriptor;
}