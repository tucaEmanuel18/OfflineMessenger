#include "user.h"

User::User()
{
    this->username = "";
    this->auth = "";
    this->connected = "";
}


User::User(string username, string auth, string connected)
{
    this->username = username;
    this->auth = auth;
    this->connected = connected;
}
