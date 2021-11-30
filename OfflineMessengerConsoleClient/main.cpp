#include <stdio.h>
#include "chat_client.h"
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	unsigned int PORT = 3705;
	string ADDRESS = "127.0.0.1";
	ChatClient client = ChatClient(ADDRESS.c_str(), PORT);
	client.run();
}
