#include "message.h"

Message::Message(string id_message, string id_sender, string id_room, string content, string reply_to, string reply_sender, string reply_content)
{
    this->id_message = id_message;
    this->id_sender = id_sender;
    this->id_room = id_room;
    this->reply_to = reply_to;
    this->content = content;
    this->reply_sender = reply_sender;
    this->reply_content = reply_content;
}

Message::Message(){

}

bool Message::IsReply(){
    return false;
}
