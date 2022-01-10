#ifndef CONNECT_PAGE_H
#define CONNECT_PAGE_H
#include "serverconnection.h"
#include "messenger_page.h"
#include <QWidget>

namespace Ui {
class connect_page;
}

class connect_page : public QWidget
{
    Q_OBJECT

public:
    explicit connect_page(QWidget *parent = nullptr);
    ~connect_page();

private:
    Ui::connect_page *ui;
    ServerConnection *server_connection;
    const string ADDRESS = "127.0.0.1";
    const unsigned int PORT = 3705;

private slots:
    void on_loginBtn_clicked();
    void on_registerBtn_clicked();
};

#endif // CONNECT_PAGE_H
