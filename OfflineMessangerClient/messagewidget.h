#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H
#include <string>
#include <QWidget>
#include <QSizePolicy>
#include <QSpacerItem>
#include <QtWidgets>
#include <message.h>
#include <serverconnection.h>
using namespace std;
namespace Ui {
class messageWidget;
}

class messageWidget : public QWidget
{
    Q_OBJECT  
public:
    void setReplyStyle();
    explicit messageWidget(QWidget *parent = nullptr, Message* message = nullptr, bool is_my_message = true, ServerConnection* server_connection = nullptr);
    ~messageWidget();

private slots:
    void on_replyBtn_clicked();

private:
    Ui::messageWidget *ui;
    Message* message;
    bool is_my_message;
    string selectedMessageId;
    ServerConnection* server_connection;

};

#endif // MESSAGEWIDGET_H
