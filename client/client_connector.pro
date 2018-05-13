#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T22:12:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client_connector
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = worms.ico

asdasd

SOURCES += \
        main.cpp \
        client_connector.cpp \
    socket.cpp \
    socket_error.cpp \
    client_lobby.cpp \
    protocol.cpp \
    client_lobby_feeder.cpp \
    protocol_error.cpp \
    thread.cpp

HEADERS += \
        client_connector.h \
    socket.h \
    socket_error.h \
    client_lobby.h \
    protocol.h \
    protocol_error.h \
    client_lobby_feeder.h \
    thread.h \
    yaml-cpp/yaml.h

FORMS += \
        client_connector.ui \
    client_lobby.ui

RESOURCES += \
    client_connector_resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lyaml-cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lyaml-cpp
else:unix: LIBS += -L$$PWD/libs/ -lyaml-cpp

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libs/release/libyaml-cpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libs/debug/libyaml-cpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libs/release/yaml-cpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libs/debug/yaml-cpp.lib
else:unix: PRE_TARGETDEPS += $$PWD/libs/libyaml-cpp.a