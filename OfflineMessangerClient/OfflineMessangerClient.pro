QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commandbuilder.cpp \
    connect_page.cpp \
    conversation.cpp \
    convthread.cpp \
    main.cpp \
    message.cpp \
    messagewidget.cpp \
    messenger_page.cpp \
    serverconnection.cpp \
    tcpscanner.cpp \
    user.cpp

HEADERS += \
    commandbuilder.h \
    connect_page.h \
    conversation.h \
    convthread.h \
    message.h \
    messagewidget.h \
    messenger_page.h \
    serverconnection.h \
    tcpscanner.h \
    user.h

FORMS += \
    connect_page.ui \
    messagewidget.ui \
    messenger_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
