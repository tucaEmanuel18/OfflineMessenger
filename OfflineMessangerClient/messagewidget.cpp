#include "messagewidget.h"
#include "ui_messagewidget.h"

messageWidget::messageWidget(QWidget *parent, Message* message, bool is_my_message, ServerConnection* server_connection) :
    QWidget(parent),
    ui(new Ui::messageWidget)
{
    ui->setupUi(this);
    this->message = message;
    this->is_my_message = is_my_message;
    this->server_connection = server_connection;
    ui->dateLabel->setText(message->time.c_str());
    ui->messageLabel->setText(message->content.c_str());
    if(message->isReply()){
        ui->replyContentLabel->setText(message->reply_content.c_str());
        ui->replyDateLabel->setText(message->reply_time.c_str());
        ui->senderLabel->setText((message->reply_username + ": ").c_str());
    }else{
        ui->reply_Wrapper->hide();
    }
    if(is_my_message){
        this->ui->leftSpacer->changeSize(2,2, QSizePolicy::Fixed, QSizePolicy::Fixed);
    }else{
        this->ui->rightSpacer->changeSize(2,2, QSizePolicy::Fixed, QSizePolicy::Fixed);
    }
}

void messageWidget::setReplyStyle(){
    this->ui->messageWrapper->setStyleSheet("background-color:#69BBAF; color:#FFFFFF");
}

messageWidget::~messageWidget()
{
    delete ui;
}

void messageWidget::on_replyBtn_clicked()
{
    this->server_connection->selectedMessageId = message->id_message;
}
