/********************************************************************************
** Form generated from reading UI file 'messagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEWIDGET_H
#define UI_MESSAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_messageWidget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *rightSpacer;
    QVBoxLayout *mainWrapper;
    QFrame *reply_Wrapper;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *replyCondentBox;
    QLabel *senderLabel;
    QLabel *replyContentLabel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *replyDetailsBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *replyDateLabel;
    QFrame *messageWrapper;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *messageLabel;
    QSpacerItem *horizontalSpacer;
    QFrame *detailsWrapper;
    QHBoxLayout *horizontalLayout;
    QPushButton *replyBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *dateLabel;
    QSpacerItem *leftSpacer;

    void setupUi(QWidget *messageWidget)
    {
        if (messageWidget->objectName().isEmpty())
            messageWidget->setObjectName(QString::fromUtf8("messageWidget"));
        messageWidget->resize(681, 135);
        messageWidget->setAutoFillBackground(true);
        messageWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(messageWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(rightSpacer);

        mainWrapper = new QVBoxLayout();
        mainWrapper->setSpacing(0);
        mainWrapper->setObjectName(QString::fromUtf8("mainWrapper"));
        reply_Wrapper = new QFrame(messageWidget);
        reply_Wrapper->setObjectName(QString::fromUtf8("reply_Wrapper"));
        reply_Wrapper->setStyleSheet(QString::fromUtf8("background:#9c9c9c; color:#f8f7f5"));
        reply_Wrapper->setFrameShape(QFrame::StyledPanel);
        reply_Wrapper->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(reply_Wrapper);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        replyCondentBox = new QHBoxLayout();
        replyCondentBox->setObjectName(QString::fromUtf8("replyCondentBox"));
        senderLabel = new QLabel(reply_Wrapper);
        senderLabel->setObjectName(QString::fromUtf8("senderLabel"));
        QFont font;
        font.setPointSize(8);
        senderLabel->setFont(font);

        replyCondentBox->addWidget(senderLabel);

        replyContentLabel = new QLabel(reply_Wrapper);
        replyContentLabel->setObjectName(QString::fromUtf8("replyContentLabel"));
        QFont font1;
        font1.setPointSize(9);
        replyContentLabel->setFont(font1);

        replyCondentBox->addWidget(replyContentLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        replyCondentBox->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(replyCondentBox);

        replyDetailsBox = new QHBoxLayout();
        replyDetailsBox->setObjectName(QString::fromUtf8("replyDetailsBox"));
        horizontalSpacer_3 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        replyDetailsBox->addItem(horizontalSpacer_3);

        replyDateLabel = new QLabel(reply_Wrapper);
        replyDateLabel->setObjectName(QString::fromUtf8("replyDateLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(replyDateLabel->sizePolicy().hasHeightForWidth());
        replyDateLabel->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(6);
        replyDateLabel->setFont(font2);

        replyDetailsBox->addWidget(replyDateLabel);


        verticalLayout_3->addLayout(replyDetailsBox);


        mainWrapper->addWidget(reply_Wrapper);

        messageWrapper = new QFrame(messageWidget);
        messageWrapper->setObjectName(QString::fromUtf8("messageWrapper"));
        messageWrapper->setStyleSheet(QString::fromUtf8("background-color:#F8F7F5"));
        messageWrapper->setFrameShape(QFrame::StyledPanel);
        messageWrapper->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(messageWrapper);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 3, -1, -1);
        messageLabel = new QLabel(messageWrapper);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(messageLabel->sizePolicy().hasHeightForWidth());
        messageLabel->setSizePolicy(sizePolicy1);
        messageLabel->setWordWrap(false);

        horizontalLayout_2->addWidget(messageLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        detailsWrapper = new QFrame(messageWrapper);
        detailsWrapper->setObjectName(QString::fromUtf8("detailsWrapper"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(detailsWrapper->sizePolicy().hasHeightForWidth());
        detailsWrapper->setSizePolicy(sizePolicy2);
        detailsWrapper->setMinimumSize(QSize(0, 20));
        detailsWrapper->setStyleSheet(QString::fromUtf8("; color:#323231"));
        detailsWrapper->setFrameShape(QFrame::StyledPanel);
        detailsWrapper->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(detailsWrapper);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 1, 0, 1);
        replyBtn = new QPushButton(detailsWrapper);
        replyBtn->setObjectName(QString::fromUtf8("replyBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(replyBtn->sizePolicy().hasHeightForWidth());
        replyBtn->setSizePolicy(sizePolicy3);
        replyBtn->setMinimumSize(QSize(15, 10));
        QFont font3;
        font3.setPointSize(7);
        replyBtn->setFont(font3);
        replyBtn->setIconSize(QSize(12, 12));
        replyBtn->setFlat(false);

        horizontalLayout->addWidget(replyBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        dateLabel = new QLabel(detailsWrapper);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setFont(font2);

        horizontalLayout->addWidget(dateLabel);


        verticalLayout->addWidget(detailsWrapper);


        mainWrapper->addWidget(messageWrapper);


        horizontalLayout_4->addLayout(mainWrapper);

        leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(leftSpacer);


        retranslateUi(messageWidget);

        QMetaObject::connectSlotsByName(messageWidget);
    } // setupUi

    void retranslateUi(QWidget *messageWidget)
    {
        messageWidget->setWindowTitle(QApplication::translate("messageWidget", "Form", nullptr));
        senderLabel->setText(QApplication::translate("messageWidget", "Sender: ", nullptr));
        replyContentLabel->setText(QApplication::translate("messageWidget", "message", nullptr));
        replyDateLabel->setText(QApplication::translate("messageWidget", "reply_date", nullptr));
        messageLabel->setText(QApplication::translate("messageWidget", "TextLabel", nullptr));
        replyBtn->setText(QApplication::translate("messageWidget", "Reply", nullptr));
        dateLabel->setText(QApplication::translate("messageWidget", "time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class messageWidget: public Ui_messageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEWIDGET_H
