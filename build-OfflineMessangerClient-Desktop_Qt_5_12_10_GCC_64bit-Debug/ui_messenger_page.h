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
#include <QtWidgets/QPlainTextEdit>
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
    QPushButton *refreshBtn;
    QVBoxLayout *chatWrapper;
    QScrollArea *chatArea;
    QWidget *chatAreaScroll;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *sendMessageWrapper;
    QPlainTextEdit *sendMessageInput;
    QPushButton *sendButton;

    void setupUi(QWidget *messenger_page)
    {
        if (messenger_page->objectName().isEmpty())
            messenger_page->setObjectName(QString::fromUtf8("messenger_page"));
        messenger_page->resize(713, 594);
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(asideWrapper->sizePolicy().hasHeightForWidth());
        asideWrapper->setSizePolicy(sizePolicy);
        asideWrapper->setMaximumSize(QSize(200, 16777215));
        asideWrapper->setToolTipDuration(-1);
        asideWrapper->setLayoutDirection(Qt::LeftToRight);
        asideWrapper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_2 = new QVBoxLayout(asideWrapper);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(asideWrapper);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(usernameLabel->sizePolicy().hasHeightForWidth());
        usernameLabel->setSizePolicy(sizePolicy1);
        usernameLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        usernameLabel->setIndent(-1);

        verticalLayout_2->addWidget(usernameLabel);

        newConvBtn = new QPushButton(asideWrapper);
        newConvBtn->setObjectName(QString::fromUtf8("newConvBtn"));

        verticalLayout_2->addWidget(newConvBtn);

        convArea = new QScrollArea(asideWrapper);
        convArea->setObjectName(QString::fromUtf8("convArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(convArea->sizePolicy().hasHeightForWidth());
        convArea->setSizePolicy(sizePolicy2);
        convArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        convArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 192, 478));
        scrollAreaWidgetContents->setMinimumSize(QSize(192, 0));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(10, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        convArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(convArea);

        refreshBtn = new QPushButton(asideWrapper);
        refreshBtn->setObjectName(QString::fromUtf8("refreshBtn"));

        verticalLayout_2->addWidget(refreshBtn);


        horizontalLayout->addWidget(asideWrapper);

        chatWrapper = new QVBoxLayout();
        chatWrapper->setObjectName(QString::fromUtf8("chatWrapper"));
        chatWrapper->setSizeConstraint(QLayout::SetNoConstraint);
        chatArea = new QScrollArea(groupBox);
        chatArea->setObjectName(QString::fromUtf8("chatArea"));
        sizePolicy.setHeightForWidth(chatArea->sizePolicy().hasHeightForWidth());
        chatArea->setSizePolicy(sizePolicy);
        chatArea->setMaximumSize(QSize(500, 800));
        chatArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        chatArea->setWidgetResizable(true);
        chatAreaScroll = new QWidget();
        chatAreaScroll->setObjectName(QString::fromUtf8("chatAreaScroll"));
        chatAreaScroll->setGeometry(QRect(0, 0, 497, 527));
        verticalLayout_4 = new QVBoxLayout(chatAreaScroll);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 506, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        chatArea->setWidget(chatAreaScroll);

        chatWrapper->addWidget(chatArea);

        sendMessageWrapper = new QHBoxLayout();
        sendMessageWrapper->setObjectName(QString::fromUtf8("sendMessageWrapper"));
        sendMessageWrapper->setSizeConstraint(QLayout::SetMinimumSize);
        sendMessageInput = new QPlainTextEdit(groupBox);
        sendMessageInput->setObjectName(QString::fromUtf8("sendMessageInput"));
        sendMessageInput->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sendMessageInput->sizePolicy().hasHeightForWidth());
        sendMessageInput->setSizePolicy(sizePolicy3);
        sendMessageInput->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(11);
        sendMessageInput->setFont(font);
        sendMessageInput->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        sendMessageInput->setPlaceholderText(QString::fromUtf8("Write a new message"));

        sendMessageWrapper->addWidget(sendMessageInput);

        sendButton = new QPushButton(groupBox);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy4);
        sendButton->setMinimumSize(QSize(0, 30));

        sendMessageWrapper->addWidget(sendButton);


        chatWrapper->addLayout(sendMessageWrapper);


        horizontalLayout->addLayout(chatWrapper);


        verticalLayout->addWidget(groupBox);


        retranslateUi(messenger_page);

        sendButton->setDefault(false);


        QMetaObject::connectSlotsByName(messenger_page);
    } // setupUi

    void retranslateUi(QWidget *messenger_page)
    {
        messenger_page->setWindowTitle(QApplication::translate("messenger_page", "Form", nullptr));
        groupBox->setTitle(QString());
        asideWrapper->setTitle(QString());
        usernameLabel->setText(QApplication::translate("messenger_page", "User", nullptr));
        newConvBtn->setText(QApplication::translate("messenger_page", "New Conversation", nullptr));
        refreshBtn->setText(QApplication::translate("messenger_page", "Refresh Conversations", nullptr));
        sendMessageInput->setPlainText(QString());
        sendButton->setText(QApplication::translate("messenger_page", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class messenger_page: public Ui_messenger_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSENGER_PAGE_H
