#ifndef MESSENGER_PAGE_H
#define MESSENGER_PAGE_H
#include "serverconnection.h"
#include "user.h"
#include "conversation.h"
#include <QWidget>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QThread>

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
    void on_pushButton_2_clicked();

private:
    vector<Conversation> conversations;
    vector<QPushButton*> conversation_widgets;
    User logged_user;
    ServerConnection *server_connection;
    Ui::messenger_page *ui;
    void conv_loop();
    void refresh_conversations();
};

#endif // MESSENGER_PAGE_H
