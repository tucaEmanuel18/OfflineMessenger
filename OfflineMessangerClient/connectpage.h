#ifndef CONNECTPAGE_H
#define CONNECTPAGE_H

#include <QMainWindow>

namespace Ui {
class ConnectPage;
}

class ConnectPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectPage(QWidget *parent = nullptr);
    ~ConnectPage();

private:
    Ui::ConnectPage *ui;
};

#endif // CONNECTPAGE_H
