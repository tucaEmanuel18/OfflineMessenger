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
#include "message.h"
#include "conversation.h"

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
    string remove_quotes(string quoted);
    User me;
public:
    ServerConnection(string address, unsigned int port);
    ServerConnection(const ServerConnection &server_connection);
    int run();
    int stop();
    User get_logged_user();


    json _register(string username, string password);
    json _log(string username, string password);
    vector<Conversation*> _get_conv();
    vector<Message*> _get_messages(string id_room);
    void _send_message(string id_room, string content, string reply_to);
    void _send_message(string id_room, string content);
};

#endif // SERVERCONNECTION_H
