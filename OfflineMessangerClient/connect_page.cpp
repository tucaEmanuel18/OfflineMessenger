#include "connect_page.h"
#include "ui_connect_page.h"
#include <QMessageBox>
#include "connect_page.h"

connect_page::connect_page(QWidget *parent, bool first_page) :
    QWidget(parent),
    ui(new Ui::connect_page)
{
    ui->setupUi(this);
    this->setWindowTitle("OfflineMessenger");
    server_connection = new ServerConnection(ADDRESS, PORT);
    int result_code;
    if((result_code = server_connection->run()) != 0){
        QMessageBox errorMsgBox;
        errorMsgBox.critical(0, "Error", strerror(result_code));
        return;

    }
}

connect_page::connect_page(QWidget *parent, ServerConnection* server_connection, bool first_page) :
    QWidget(parent),
    ui(new Ui::connect_page)
{
    ui->setupUi(this);
    this->setWindowTitle("OfflineMessenger");
    server_connection = server_connection;
}


connect_page::~connect_page()
{
    delete ui;
}
void connect_page:: on_loginBtn_clicked(){
    printf("[LOG] Login button clicked!\n");
    fflush(stdout);
    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();

    json response = server_connection->_log(username.toStdString(), password.toStdString());
    if(response.at("status") == 200){
        messenger_page *messengerWidget = new messenger_page(nullptr, this->server_connection);
        messengerWidget->show();
        deleteLater();
    }else{
        if(response["status"] == 500){
                QMessageBox::critical(this, "Error", response["message"].dump().c_str());
            }else{
                QMessageBox::warning(this, "Warning", response["message"].dump().c_str());
            }
    }
}

void connect_page::on_registerBtn_clicked(){
    printf("[LOG] Register button clicked!\n");
    fflush(stdout);
    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();

    json response = server_connection->_register(username.toStdString(), password.toStdString());
    if(response.at("status") == 201){
        QMessageBox::information(this, "Register", response["message"].dump().c_str());
    }else if(response["status"] == 500){
        QMessageBox::critical(this, "Error", response["message"].dump().c_str());
    }else{
        QMessageBox::warning(this, "Warning", response["message"].dump().c_str());
    }
}

void connect_page::closeEvent(QCloseEvent *event){
       if (event->spontaneous()) {
            server_connection->stop();
       } else {
           QWidget::closeEvent(event);
       }
   }

