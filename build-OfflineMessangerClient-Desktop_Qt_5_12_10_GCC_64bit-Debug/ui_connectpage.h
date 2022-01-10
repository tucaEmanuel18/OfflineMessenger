/********************************************************************************
** Form generated from reading UI file 'connectpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTPAGE_H
#define UI_CONNECTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectPage
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConnectPage)
    {
        if (ConnectPage->objectName().isEmpty())
            ConnectPage->setObjectName(QString::fromUtf8("ConnectPage"));
        ConnectPage->resize(800, 600);
        centralwidget = new QWidget(ConnectPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(180, 210, 104, 70));
        ConnectPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConnectPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ConnectPage->setMenuBar(menubar);
        statusbar = new QStatusBar(ConnectPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ConnectPage->setStatusBar(statusbar);

        retranslateUi(ConnectPage);

        QMetaObject::connectSlotsByName(ConnectPage);
    } // setupUi

    void retranslateUi(QMainWindow *ConnectPage)
    {
        ConnectPage->setWindowTitle(QApplication::translate("ConnectPage", "MainWindow", nullptr));
        plainTextEdit->setPlainText(QApplication::translate("ConnectPage", "connect page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectPage: public Ui_ConnectPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTPAGE_H
