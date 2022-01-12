#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>

namespace Ui {
class messageWidget;
}

class messageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit messageWidget(QWidget *parent = nullptr);
    ~messageWidget();

private:
    Ui::messageWidget *ui;
};

#endif // MESSAGEWIDGET_H
