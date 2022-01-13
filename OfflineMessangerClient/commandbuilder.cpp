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

json CommandBuilder::_get_messages(string auth, string id_room){
    json json_message;
    json_message = {
            {"command", "get_msg"},
            {"auth", auth.c_str()},
            {"id_room", id_room.c_str()}
    };
    return json_message;
}

json CommandBuilder::_send_message(string auth, string id_room, string content, string reply_to){
    json json_message;
    json_message = {
            {"command", "create_msg"},
            {"auth", auth.c_str()},
            {"id_room", id_room.c_str()},
            {"content", content.c_str()},
            {"reply_to", reply_to.c_str()}
    };
    return json_message;
}

json CommandBuilder::_send_message(string auth, string id_room, string content){
    json json_message;
    json_message = {
            {"command", "create_msg"},
            {"auth", auth.c_str()},
            {"id_room", id_room.c_str()},
            {"content", content.c_str()}
    };
    return json_message;
}

json CommandBuilder::_create_conv(string auth, string friend_username){
    json json_message;
    json_message = {
            {"command", "create_conv"},
            {"auth", auth.c_str()},
            {"friend_username", friend_username}
    };
    return json_message;
}

json CommandBuilder::_log_out(string auth){
    json json_message;
    json_message = {
            {"command", "log_out"},
            {"auth", auth.c_str()}
    };
    return json_message;
}

json CommandBuilder::_quit(){
    json json_message;
    json_message = {
            {"command", "quit"}
    };
    return json_message;
}

