#ifndef MESSENGER_PAGE_H
#define MESSENGER_PAGE_H
#include "serverconnection.h"
#include "user.h"
#include "conversation.h"
#include "message.h"
#include <QWidget>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QThread>
#include <QTimer>

namespace Ui {
class messenger_page;
}

class messenger_page : public QWidget
{
    Q_OBJECT

public:
    explicit messenger_page(QWidget *parent = nullptr, ServerConnection *server_connection = nullptr);
    ~messenger_page();

private slots:
    void on_getMessagesTriggered();
    void on_refreshBtn_clicked();
    void on_sendMessageInput_textChanged();

    void on_sendButton_clicked();

private:
    vector<Conversation*> conversations;
    vector<QPushButton*> conversation_widgets;
    QTimer* conversation_timer;

    Conversation selectedConversation;
    vector<Message*> messages;
    vector<QLabel*> message_widgets;
    QTimer* chat_timer;

    User logged_user;
    ServerConnection *server_connection;
    Ui::messenger_page *ui;
    void conv_loop();
    void chat_loop();
    void refresh_conversations();
    void refresh_messages();
};

#endif // MESSENGER_PAGE_H
