#ifndef CONVTHREAD_H
#define CONVTHREAD_H
#include "serverconnection.h"
#include <QThread>
#include <QWidget>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include "conversation.h"
#include <vector>

class ConvThread : public QThread
{
    Q_OBJECT
private:
    void addConversationButton(Conversation conversation);
protected:
    void run();
    QWidget *conv_area;
    ServerConnection *server_connection;
public:
    ConvThread(QWidget *conv_area = nullptr, ServerConnection *server_connection = nullptr);
    vector<Conversation> conversations;
};

#endif // CONVTHREAD_H
