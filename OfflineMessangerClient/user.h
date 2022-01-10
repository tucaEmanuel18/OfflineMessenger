#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

class User
{

public:
    string username;
    string auth;
    string connected;
    User(string username, string auth, string connected);
    User();
};

#endif // USER_H
