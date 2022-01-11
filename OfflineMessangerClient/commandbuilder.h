#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;
class CommandBuilder
{
public:
    CommandBuilder();
    json _register(string username, string password);
    json _log(string username, string password);
    json _get_conv(string auth);
    json _get_messages(string auth, string id_room);
};

#endif // COMMANDBUILDER_H
