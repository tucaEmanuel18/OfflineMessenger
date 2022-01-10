#ifndef CONVERSATION_H
#define CONVERSATION_H
#include "user.h"

class Conversation
{
public:
    string id_room;
    User participant;
    Conversation(string id_room, string id_user, string username, string connected);
};

#endif // CONVERSATION_H
