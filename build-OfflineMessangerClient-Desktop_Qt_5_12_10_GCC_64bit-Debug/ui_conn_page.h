/********************************************************************************
** Form generated from reading UI file 'conn_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONN_PAGE_H
#define UI_CONN_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_conn_page
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *conn_page)
    {
        if (conn_page->objectName().isEmpty())
            conn_page->setObjectName(QString::fromUtf8("conn_page"));
        conn_page->resize(800, 600);
        centralwidget = new QWidget(conn_page);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(400, 160, 104, 70));
        conn_page->setCentralWidget(centralwidget);
        menubar = new QMenuBar(conn_page);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        conn_page->setMenuBar(menubar);
        statusbar = new QStatusBar(conn_page);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        conn_page->setStatusBar(statusbar);

        retranslateUi(conn_page);

        QMetaObject::connectSlotsByName(conn_page);
    } // setupUi

    void retranslateUi(QMainWindow *conn_page)
    {
        conn_page->setWindowTitle(QApplication::translate("conn_page", "MainWindow", nullptr));
        plainTextEdit->setPlainText(QApplication::translate("conn_page", "Conn page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class conn_page: public Ui_conn_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONN_PAGE_H
