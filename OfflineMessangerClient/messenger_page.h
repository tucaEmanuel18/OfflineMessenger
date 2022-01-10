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

private:
    vector<Conversation> conversations;
    User logged_user;
    ServerConnection *server_connection;
    Ui::messenger_page *ui;
    void conv_loop();
};

#endif // MESSENGER_PAGE_H
