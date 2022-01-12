#include "message.h"

Message::Message(string id_message, string id_sender, string id_room, string content, string time)
{
    this->id_message = id_message;
    this->id_sender = id_sender;
    this->content = content;
    this->id_room = id_room;
    this->time = time;
    this->is_set = true;
}

Message::Message(){
    is_set = false;
}

void Message::setReplyToMessage(string reply_to, string reply_sender, string reply_content, string reply_time){
    if(reply_to.compare("NULL") != 0){
        this->reply_to = reply_to;
        this->reply_sender = reply_sender;
        this->reply_content = reply_content;
        this->reply_time = reply_time;
    }else{
        throw std::invalid_argument("Call setReplyToMessage method with an unset reply_to message!");
    }
}

void Message::setReplyUsername(string reply_username){
    this->reply_username = reply_username;
}

bool Message::isReply(){
    return !reply_to.empty();
}

bool Message::isSet(){
    return is_set;
}
