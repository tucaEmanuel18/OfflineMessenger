#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>

using namespace std;

class Message
{
public:
    string id_message;
    string id_sender;
    string id_room;
    string content;
    string reply_to;
    string reply_sender;
    string reply_content;
    Message(string id_message, string id_sender, string id_room, string content, string reply_to, string reply_sender, string reply_content);
    Message();
    bool IsReply();
};

#endif // MESSAGE_H
