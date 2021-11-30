#include <stdio.h>
#include "chat_server.h"
int main(int argc, char **argv)
{
	unsigned int PORT = 3705;
    unsigned int BACKLOG = 5;
    ChatServer server = ChatServer(PORT, BACKLOG);
    server.start();
}
