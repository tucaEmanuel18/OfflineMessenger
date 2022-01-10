#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>
#include <nlohmann/json.hpp>
#include "tcpscanner.h"
#include "commandbuilder.h"
#include "user.h"

using json = nlohmann::json;
using namespace std;
class ServerConnection
{
private:
    string address;
    unsigned int port;
    int socket_descriptor;
    struct sockaddr_in client_socket;
    TCPScanner scanner;
    CommandBuilder command_builder;
    json send_request(string command);
    User me;
public:
    ServerConnection(string address, unsigned int port);
    ServerConnection(const ServerConnection &server_connection);
    int run();
    int stop();
    User get_logged_user();


    json _register(string username, string password);
    json _log(string username, string password);
    json _get_conv();
};

#endif // SERVERCONNECTION_H