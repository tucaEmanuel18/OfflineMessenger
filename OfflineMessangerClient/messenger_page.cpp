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
    ui->chatLabel->setText("Select a conversation to see messages here!");
    this->ui->chatArea->verticalScrollBar()->setSliderPosition(this->ui->chatArea->verticalScrollBar()->maximum());
    conv_loop();
    chat_loop();
}

messenger_page::~messenger_page()
{
    delete ui;
}

void messenger_page::on_getMessagesTriggered(){
    QPushButton* w_conversation = qobject_cast<QPushButton*>(sender());

    std::vector<QPushButton*>::iterator it = std::find(conversation_widgets.begin(), conversation_widgets.end(), w_conversation);
    Conversation *conversation = nullptr;
    if (it == conversation_widgets.end()){
        QMessageBox::critical(nullptr, "Error", "Something went wrong when trying to find which button was pressed!");
    }
    else{
        this->ui->chatLabel->hide();
        server_connection->selectedMessageId = "";
        this->ui->sendMessageInput->setPlainText("");
        int index = std::distance(conversation_widgets.begin(), it);
        conversation = conversations.at(index);
        selectedConversation = *conversation;
        this->ui->sendMessageInput->setEnabled(true);
        refresh_messages();
    }
}
void messenger_page::refresh_conversations(){
    for(unsigned int i = 0; i < conversation_widgets.size(); i++){
        delete conversation_widgets.at(i);
        delete conversations.at(i);
    }
    conversations.clear();
    conversation_widgets.clear();

    try {
        conversations = this->server_connection->_get_conv();
        for(auto conversation : conversations){
            QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->ui->scrollAreaWidgetContents->layout());
            QPushButton *button = new QPushButton(conversation->participant.username.c_str(), this->ui->scrollAreaWidgetContents);

            if(conversation->participant.connected.compare("1") == 0){
                button->setStyleSheet("background-color:#69BBAF; color:#FFFFFF");
            }else{
                button->setStyleSheet("background-color:#f74f4f; color:#FFFFFF");
            }

            if(conversation->id_room == selectedConversation.id_room){
                button->setStyleSheet("background-color:#9c9c9c; color:#FFFFFF");
            }

            QObject::connect(button, &QPushButton::clicked, this, &messenger_page::on_getMessagesTriggered);
            layout->insertWidget(0, button);
            this->ui->convArea->verticalScrollBar()->setSliderPosition(this->ui->convArea->verticalScrollBar()->maximum());
            conversation_widgets.push_back(button);
        }
    }  catch (std::invalid_argument const& e) {
        QMessageBox::critical(nullptr, "Error", e.what());
    }
}

void messenger_page::refresh_messages(){
    if(selectedConversation.isSet()){
        for(unsigned int i = 0; i < message_widgets.size(); i++){
            delete message_widgets.at(i);
            delete messages.at(i);
        }
        messages.clear();
        message_widgets.clear();
        try{
            messages = this->server_connection->_get_messages(selectedConversation.id_room);
            QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->ui->chatAreaScroll->layout());
            if(messages.size() == 0){
                this->ui->chatLabel->setText("You haven't talked to this person before! You can start now!");
                this->ui->chatLabel->show();
            }
            for (auto message : messages){
                bool is_my_message = message->id_sender == this->server_connection->get_logged_user().auth? true: false;

                if(message->isReply()){
                    message->setReplyUsername(server_connection->get_logged_user().auth.compare(message->reply_sender) == 0
                                              ? server_connection->get_logged_user().username
                                              : selectedConversation.participant.username);
                }

                messageWidget *w_message = new messageWidget(this, message, is_my_message, server_connection);
                if(message->id_message.compare(server_connection->selectedMessageId) == 0){
                    w_message->setReplyStyle();
                }
                layout->insertWidget(1, w_message);
                this->ui->chatArea->verticalScrollBar()->setSliderPosition(this->ui->chatArea->verticalScrollBar()->maximum());
                message_widgets.push_back(w_message);
            }
        }catch(std::domain_error const& e){
            QMessageBox::critical(nullptr, "Error", e.what());
        }catch(std::invalid_argument const& e){
            QMessageBox::warning(nullptr, "Error", e.what());
        }
    }
}

void messenger_page::on_sendMessageInput_textChanged()
{
    if(this->ui->sendMessageInput->toPlainText().isEmpty()){
        this->ui->sendButton->setEnabled(false);
        this->ui->sendButton->setStyleSheet("background-color:#ade0d9; color:#7d7d7d");
    }else{
        this->ui->sendButton->setEnabled(true);
        this->ui->sendButton->setStyleSheet("background-color:#69BBAF; color:#323231");
    }
}

void messenger_page::on_sendButton_clicked()
{
    string content = this->ui->sendMessageInput->toPlainText().toStdString();
    if(!content.empty() && selectedConversation.isSet()){
        try{
            server_connection->_send_message(selectedConversation.id_room, content);
            this->ui->sendMessageInput->setPlainText("");
            server_connection->selectedMessageId = "";
            refresh_messages();
        }catch(std::domain_error const& e){
            QMessageBox::critical(nullptr, "Error", e.what());
        }catch(std::invalid_argument const& e){
            QMessageBox::warning(nullptr, "Error", e.what());
        }
    }
}

void messenger_page::on_newConvBtn_clicked()
{
    bool ok;
    QString friend_username = QInputDialog::getText(this, tr("New conversation"),
                                             tr("Get your friend username:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
    if(ok){
        if(friend_username.isEmpty()){
            QMessageBox::warning(nullptr, "Warning", "The friend username can not be empty! Please try again!");
        }else{
            try{
                server_connection->_create_conv(friend_username.toStdString());
            } catch(std::domain_error const& e){
                QMessageBox::critical(nullptr, "Error", e.what());
            }catch(std::invalid_argument const& e){
                QMessageBox::warning(nullptr, "Error", e.what());
            }

        }
    }
}

void messenger_page::on_logOutBtn_clicked()
{
    try{
        server_connection->_log_out();
        this->selectedConversation = Conversation();
        server_connection->selectedMessageId = "";
    } catch(std::domain_error const& e){
        QMessageBox::critical(nullptr, "Error", e.what());
    }catch(std::invalid_argument const& e){
        QMessageBox::warning(nullptr, "Error", e.what());
    }
    connect_page *w_connect = new connect_page(nullptr, this->server_connection, false);
    w_connect->show();
    deleteLater();
}

void messenger_page::conv_loop(){
    refresh_conversations();
    conversation_timer = new QTimer(this);
    connect(conversation_timer, &QTimer::timeout, this, QOverload<>::of(&messenger_page::refresh_conversations));
    conversation_timer->start(1000);
}

void messenger_page::chat_loop(){
    chat_timer = new QTimer(this);
    connect(chat_timer, &QTimer::timeout, this, QOverload<>::of(&messenger_page::refresh_messages));
    chat_timer->start(1000);
}

void messenger_page::closeEvent(QCloseEvent *event){
       if (event->spontaneous()) {
            server_connection->stop();
       } else {
           QWidget::closeEvent(event);
       }
   }


