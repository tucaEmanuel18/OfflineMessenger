#pragma once
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdexcept>
#include <unistd.h>
#include <stdexcept>
#include <iostream>

using namespace std;

class TCPScanner
{
private:
	static unsigned const int BUFFER_SIZE = 4096;
	unsigned int socket_descriptor;
	char* buffer = new char[BUFFER_SIZE];
public:
	TCPScanner();
	~TCPScanner();
	void Write(string message);
	string Read();
	void set_socket_descriptor(unsigned int socket_descriptor);
};