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
    new std::thread([this](){this->conv_loop();});
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

                QPushButton *button = new QPushButton(username.c_str(), nullptr);
                layout->insertWidget(0, button);
            }

        }else{
            QMessageBox::critical(nullptr, "Error", response["message"].dump().c_str());
        }
        sleep(5);
    }
}
