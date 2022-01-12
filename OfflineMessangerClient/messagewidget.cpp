#include "messagewidget.h"
#include "ui_messagewidget.h"

messageWidget::messageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messageWidget)
{
    ui->setupUi(this);
}

messageWidget::~messageWidget()
{
    delete ui;
}
