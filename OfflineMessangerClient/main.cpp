#include "connect_page.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connect_page * c_page = new connect_page();
    c_page->show();

    return a.exec();
}
