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

        sleep(5);
    }
}

void ConvThread::addConversationButton(Conversation conversation){
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(conv_area->layout());

    QPushButton *button = new QPushButton(conversation.participant.username.c_str(), conv_area);
    layout->insertWidget(0, button);
}
