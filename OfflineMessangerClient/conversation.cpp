#include "conversation.h"

Conversation::Conversation(string id_room, string id_user, string username, string connected)
{
    this->id_room = id_room;
    this->participant = User(username, id_user, connected);
}
