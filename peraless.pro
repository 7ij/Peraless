QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    configurations.cpp \
    main.cpp \
    mainwindow.cpp \
    makeHotKeyConnections.cpp \
    makeWebSocketSignalSlotConnections.cpp \
    myconcurrentdelaymachine.cpp \
    mydelaymachine.cpp \
    mypopup.cpp \
    onTextChanged.cpp \
    on_btnClear_clicked.cpp \
    on_btnConenct_clicked.cpp \
    on_btnDisconnect_clicked.cpp \
    on_btnStartListening_clicked.cpp \
    shortcutHandle.cpp \
    aboutwindow.cpp

HEADERS += \
    mainwindow.h \
    myconcurrentdelaymachine.h \
    mydelaymachine.h \
    mypopup.h \
    aboutwindow.h

FORMS += \
    mainwindow.ui \
    aboutwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#LIBS += "/home/nayeem/Documents/DevP/QT/websocket/build-websocket-Desktop-Debug/libUGlobalHotkey.so"

#LIBS += "/home/nayeem/Documents/DevP/QT/websocket/build-websocket-Desktop-Debug/libUGlobalHotkey.so.1"

#LIBS += "/home/nayeem/Documents/DevP/QT/websocket/build-websocket-Desktop-Debug/libUGlobalHotkey.so.1.0"

#LIBS += "/home/nayeem/Documents/DevP/QT/websocket/build-websocket-Desktop-Debug/libUGlobalHotkey.so.1.0.0"
CONFIG -= console
RC_ICONS = mic.ico
