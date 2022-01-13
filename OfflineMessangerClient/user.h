#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

class User
{
private:
    bool is_set;
public:
    string username;
    string auth;
    string connected;
    User(string username, string auth, string connected);
    User();

    bool isSet();
};

#endif // USER_H
