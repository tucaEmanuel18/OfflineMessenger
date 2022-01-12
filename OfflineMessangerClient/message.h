#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <stdexcept>
using namespace std;

class Message
{
private:
    bool is_set;
public:
    string id_message;
    string id_sender;
    string id_room;
    string content;
    string time;
    string reply_to;
    string reply_sender;
    string reply_content;
    string reply_time;
//    Message *reply_to;

    Message(string id_message, string id_sender, string id_room, string content, string time);
    Message();
    bool isReply();
    bool isSet();
//    void set(string id_message, string id_sender, string id_room, string content, string time);
//    void setReplyToMessage(Message *reply_to);
    void setReplyToMessage(string reply_to, string reply_sender, string reply_content, string reply_time);
};

#endif // MESSAGE_H
