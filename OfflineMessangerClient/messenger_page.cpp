#include "messenger_page.h"
#include "ui_messenger_page.h"

messenger_page::messenger_page(QWidget *parent, ServerConnection *server_connection) :
    QWidget(parent),
    ui(new Ui::messenger_page)
{
    ui->setupUi(this);
    this->setWindowTitle("OfflineMessenger");
    this->server_connection = server_connection;
    this->logged_user = server_connection->get_logged_user();
    ui->usernameLabel->setText(logged_user.username.c_str());
    refresh_conversations();
//    new std::thread([this](){this->conv_loop();});
//    ConvThread *conv_thread = new ConvThread(ui->scrollAreaWidgetContents, server_connection);
//    printf("[LOG] Am pornit procesul pentru conversatii!\n");
//    fflush(stdout);
//    conv_thread->start();
//    printf("[LOG] Am pornit procesul pentru conversatii!");
//    fflush(stdout);
}

messenger_page::~messenger_page()
{
    delete ui;
}

void messenger_page::on_pushButton_2_clicked()
{
    refresh_conversations();
}

void messenger_page::refresh_conversations(){
    json response = this->server_connection->_get_conv();
    if(response["status"] == 200){
        for(unsigned int i = 0; i < conversation_widgets.size(); i++){
            delete conversation_widgets.at(i);
            delete conversations.at(i);
        }
        conversations.clear();
        conversation_widgets.clear();
        json j_conversations = response["conversations"];
        for(unsigned long i=0; i < j_conversations.size(); i++){
            string id_room = j_conversations.at(i).at("id_room").dump().c_str();
            string id_user = j_conversations.at(i).at("id_user").dump().c_str();
            string username = j_conversations.at(i).at("username").dump().c_str();
            string connected = j_conversations.at(i).at("connected").dump().c_str();
            Conversation* new_conversation = new Conversation(id_room, id_user, username, connected);
            conversations.push_back(new_conversation);
            QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->ui->scrollAreaWidgetContents->layout());

            QPushButton *button = new QPushButton(username.c_str(), this->ui->scrollAreaWidgetContents);
            QObject::connect(button, &QPushButton::clicked, this, &messenger_page::on_conversationBtn_clicked);
            layout->insertWidget(0, button);
            conversation_widgets.push_back(button);
        }

    }else{
        QMessageBox::critical(nullptr, "Error", response["message"].dump().c_str());
    }
}

void messenger_page::on_conversationBtn_clicked(){
    QPushButton* w_conversation = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    std::vector<QPushButton*>::iterator it = std::find(conversation_widgets.begin(), conversation_widgets.end(), w_conversation);
    Conversation *conversation = nullptr;
    if (it != conversation_widgets.end()){
        int index = std::distance(conversation_widgets.begin(), it);
        conversation = conversations.at(index);
    }
    else{
        QMessageBox::critical(nullptr, "Error", "Something went wrong when trying to find which button was pressed!");
    }

    json response = this->server_connection->_get_messeges()
    if(response["status"] == 200){
        conversations.clear();

        for(auto conversation : conversation_widgets){
            delete conversation;
        }

        conversation_widgets.clear();
        json j_conversations = response["conversations"];
        for(unsigned long i=0; i < j_conversations.size(); i++){
            string id_room = j_conversations.at(i).at("id_room").dump().c_str();
            string id_user = j_conversations.at(i).at("id_user").dump().c_str();
            string username = j_conversations.at(i).at("username").dump().c_str();
            string connected = j_conversations.at(i).at("connected").dump().c_str();
            Conversation new_conversation = Conversation(id_room, id_user, username, connected);
            conversations.push_back(new_conversation);
            QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->ui->scrollAreaWidgetContents->layout());

            QPushButton *button = new QPushButton(username.c_str(), this->ui->scrollAreaWidgetContents);
            QObject::connect(button, &QPushButton::clicked, this, &messenger_page::on_conversationBtn_clicked);
            layout->insertWidget(0, button);
            conversation_widgets.push_back(button);
        }

    }else{
        QMessageBox::critical(nullptr, "Error", response["message"].dump().c_str());
    }
}



void messenger_page::conv_loop(){
    while(1){
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
                QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->ui->scrollAreaWidgetContents->layout());

                QPushButton *button = new QPushButton(username.c_str(), this->ui->scrollAreaWidgetContents);
                layout->insertWidget(0, button);
            }

        }else{
            QMessageBox::critical(nullptr, "Error", response["message"].dump().c_str());
        }
        sleep(5);
    }
}
