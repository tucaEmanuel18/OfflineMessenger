#ifndef CONVERSATION_H
#define CONVERSATION_H
#include "user.h"

class Conversation
{
private:
    bool is_set;
public:
    string id_room;
    User participant;
    Conversation(string id_room, string id_user, string username, string connected);
    Conversation();
    bool isSet();

};

#endif // CONVERSATION_H
