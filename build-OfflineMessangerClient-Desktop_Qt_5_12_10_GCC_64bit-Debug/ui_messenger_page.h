/********************************************************************************
** Form generated from reading UI file 'messenger_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSENGER_PAGE_H
#define UI_MESSENGER_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_messenger_page
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGroupBox *asideWrapper;
    QVBoxLayout *verticalLayout_2;
    QLabel *usernameLabel;
    QPushButton *newConvBtn;
    QScrollArea *convArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;

    void setupUi(QWidget *messenger_page)
    {
        if (messenger_page->objectName().isEmpty())
            messenger_page->setObjectName(QString::fromUtf8("messenger_page"));
        messenger_page->resize(737, 594);
        verticalLayout = new QVBoxLayout(messenger_page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(messenger_page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        asideWrapper = new QGroupBox(groupBox);
        asideWrapper->setObjectName(QString::fromUtf8("asideWrapper"));
        asideWrapper->setMaximumSize(QSize(200, 16777215));
        verticalLayout_2 = new QVBoxLayout(asideWrapper);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(asideWrapper);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(usernameLabel);

        newConvBtn = new QPushButton(asideWrapper);
        newConvBtn->setObjectName(QString::fromUtf8("newConvBtn"));

        verticalLayout_2->addWidget(newConvBtn);

        convArea = new QScrollArea(asideWrapper);
        convArea->setObjectName(QString::fromUtf8("convArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(convArea->sizePolicy().hasHeightForWidth());
        convArea->setSizePolicy(sizePolicy);
        convArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 192, 469));
        scrollAreaWidgetContents->setMinimumSize(QSize(192, 0));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        convArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(convArea);

        pushButton_2 = new QPushButton(asideWrapper);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout->addWidget(asideWrapper);

        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMaximumSize(QSize(500, 800));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 498, 567));
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(scrollArea);


        verticalLayout->addWidget(groupBox);


        retranslateUi(messenger_page);

        QMetaObject::connectSlotsByName(messenger_page);
    } // setupUi

    void retranslateUi(QWidget *messenger_page)
    {
        messenger_page->setWindowTitle(QApplication::translate("messenger_page", "Form", nullptr));
        groupBox->setTitle(QString());
        asideWrapper->setTitle(QString());
        usernameLabel->setText(QApplication::translate("messenger_page", "User", nullptr));
        newConvBtn->setText(QApplication::translate("messenger_page", "New Conversation", nullptr));
        pushButton_2->setText(QApplication::translate("messenger_page", "Refresh Conversations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class messenger_page: public Ui_messenger_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSENGER_PAGE_H
