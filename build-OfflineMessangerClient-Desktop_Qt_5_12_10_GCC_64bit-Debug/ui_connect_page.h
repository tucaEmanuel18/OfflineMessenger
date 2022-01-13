/********************************************************************************
** Form generated from reading UI file 'connect_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_PAGE_H
#define UI_CONNECT_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connect_page
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *mainWrapper;
    QVBoxLayout *fromBox;
    QHBoxLayout *titleBox;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *usernameField;
    QLabel *usernameLabel;
    QLineEdit *usernameInput;
    QHBoxLayout *passwordField;
    QLabel *passwordLabel;
    QLineEdit *passwordInput;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *btnBox;
    QPushButton *loginBtn;
    QPushButton *registerBtn;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *connect_page)
    {
        if (connect_page->objectName().isEmpty())
            connect_page->setObjectName(QString::fromUtf8("connect_page"));
        connect_page->resize(700, 369);
        connect_page->setStyleSheet(QString::fromUtf8("background-color:#f8f7f5"));
        horizontalLayout = new QHBoxLayout(connect_page);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mainWrapper = new QVBoxLayout();
        mainWrapper->setSpacing(6);
        mainWrapper->setObjectName(QString::fromUtf8("mainWrapper"));
        fromBox = new QVBoxLayout();
        fromBox->setObjectName(QString::fromUtf8("fromBox"));
        fromBox->setContentsMargins(50, 20, 50, 50);
        titleBox = new QHBoxLayout();
        titleBox->setObjectName(QString::fromUtf8("titleBox"));
        titleLabel = new QLabel(connect_page);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setPointSize(20);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("color:#69bbaf"));

        titleBox->addWidget(titleLabel);


        fromBox->addLayout(titleBox);

        verticalSpacer = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Preferred);

        fromBox->addItem(verticalSpacer);

        usernameField = new QHBoxLayout();
        usernameField->setObjectName(QString::fromUtf8("usernameField"));
        usernameLabel = new QLabel(connect_page);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        QFont font1;
        font1.setPointSize(14);
        usernameLabel->setFont(font1);
        usernameLabel->setStyleSheet(QString::fromUtf8("color:#69BBAF"));

        usernameField->addWidget(usernameLabel);

        usernameInput = new QLineEdit(connect_page);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));
        QFont font2;
        font2.setPointSize(12);
        usernameInput->setFont(font2);
        usernameInput->setStyleSheet(QString::fromUtf8("background-color:white; color:#69BBAF"));

        usernameField->addWidget(usernameInput);


        fromBox->addLayout(usernameField);

        passwordField = new QHBoxLayout();
        passwordField->setObjectName(QString::fromUtf8("passwordField"));
        passwordLabel = new QLabel(connect_page);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setFont(font1);
        passwordLabel->setStyleSheet(QString::fromUtf8("color:#69BBAF"));

        passwordField->addWidget(passwordLabel);

        passwordInput = new QLineEdit(connect_page);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setFont(font2);
        passwordInput->setStyleSheet(QString::fromUtf8("background-color:white; color:#69BBAF"));
        passwordInput->setEchoMode(QLineEdit::Password);

        passwordField->addWidget(passwordInput);


        fromBox->addLayout(passwordField);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        fromBox->addItem(verticalSpacer_2);

        btnBox = new QHBoxLayout();
        btnBox->setObjectName(QString::fromUtf8("btnBox"));
        loginBtn = new QPushButton(connect_page);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setFont(font2);
        loginBtn->setCursor(QCursor(Qt::PointingHandCursor));
        loginBtn->setStyleSheet(QString::fromUtf8("background-color:#69BBAF; color:#FFFFFF"));

        btnBox->addWidget(loginBtn);

        registerBtn = new QPushButton(connect_page);
        registerBtn->setObjectName(QString::fromUtf8("registerBtn"));
        registerBtn->setFont(font2);
        registerBtn->setCursor(QCursor(Qt::PointingHandCursor));
        registerBtn->setStyleSheet(QString::fromUtf8("background-color:#f74f4f; color:#ffffff"));

        btnBox->addWidget(registerBtn);


        fromBox->addLayout(btnBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        fromBox->addItem(verticalSpacer_3);


        mainWrapper->addLayout(fromBox);


        horizontalLayout->addLayout(mainWrapper);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(connect_page);

        QMetaObject::connectSlotsByName(connect_page);
    } // setupUi

    void retranslateUi(QWidget *connect_page)
    {
        connect_page->setWindowTitle(QApplication::translate("connect_page", "Form", nullptr));
        titleLabel->setText(QApplication::translate("connect_page", "Login/Register", nullptr));
        usernameLabel->setText(QApplication::translate("connect_page", "Username", nullptr));
        usernameInput->setPlaceholderText(QString());
        passwordLabel->setText(QApplication::translate("connect_page", "Password", nullptr));
        passwordInput->setPlaceholderText(QString());
        loginBtn->setText(QApplication::translate("connect_page", "Login", nullptr));
        registerBtn->setText(QApplication::translate("connect_page", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connect_page: public Ui_connect_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_PAGE_H
