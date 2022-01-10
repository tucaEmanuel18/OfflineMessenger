#include "commandbuilder.h"

CommandBuilder::CommandBuilder()
{

}

json CommandBuilder::_register(string username, string password){
    json json_message;
    json_message["command"] = "register";
    json_message["username"] = username.c_str();
    json_message["password"] = password.c_str();

    return json_message;
}


json CommandBuilder::_log(string username, string password){
    json json_message;
    json_message["command"] = "log";
    json_message["username"] = username.c_str();
    json_message["password"] = password.c_str();

    return json_message;
}

json CommandBuilder::_get_conv(string auth){
    json json_message;
    json_message = {
            {"command", "get_conv"},
            {"auth", auth.c_str()}
    };
    return json_message;
}

json CommandBuilder::_get_messeges(string auth, string id_room){
    json json_message;
    json_message = {
            {"command", "get_msg"},
            {"auth", auth.c_str()},
            {"id_room", id_room.c_str()}
    };
    return json_message;
}
