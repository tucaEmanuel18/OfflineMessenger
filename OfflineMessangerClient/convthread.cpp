#include "convthread.h"

ConvThread::ConvThread(QWidget *conv_area, ServerConnection *server_connection)
{
    this->conv_area = conv_area;
    this->server_connection = new ServerConnection(*server_connection);
}

void ConvThread::run(){
    printf("Sunt in thread!\n");
    fflush(stdout);

    while(1){
        printf("Super!\n");
        fflush(stdout);

        json response = this->server_connection->_get_conv();
        if(response["status"] == 200){
            json j_conversations = response["conversations"];
            for(unsigned long i=0; i < j_conversations.size(); i++){
                string id_room = j_conversations.at(i).at("id_room").dump().c_str();
                string id_user = j_conversations.at(i).at("id_user").dump().c_str();
                string username = j_conversations.at(i).at("username").dump().c_str();
                string connected = j_conversations.at(i).at("connected").dump().c_str();
                Conversation new_conversation = Conversation(id_room, id_user, username, connected);
                conversations.push_back(new_conversation);
                addConversationButton(new_conversation);
            }

        }else{
            QMessageBox::critical(nullptr, "Error", response["message"].dump().c_str());
            exit();
        }
        sleep(5);
    }
}

void ConvThread::addConversationButton(Conversation conversation){
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(conv_area->layout());

    QPushButton *button = new QPushButton(conversation.participant.username.c_str(), conv_area);
    layout->insertWidget(0, button);
}
