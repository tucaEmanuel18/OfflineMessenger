#include "user.h"

User::User()
{
    this->username = "";
    this->auth = "";
    this->connected = "";
    is_set = false;
}


User::User(string username, string auth, string connected)
{
    this->username = username;
    this->auth = auth;
    this->connected = connected;
    is_set = true;
}

bool User::isSet(){
    return is_set;
}
