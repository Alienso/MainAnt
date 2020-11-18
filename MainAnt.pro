QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./src/main.cpp \
    ./src/mainwindow.cpp \
    src/Input.cpp \
    src/InputNode.cpp \
    src/Node.cpp \
    src/Output.cpp \
    src/BinaryFunction.cpp \
    src/Parser.cpp \
    src/PrintNode.cpp \
    src/ReturnNode.cpp

HEADERS += \
    ./headers/mainwindow.h \
    headers/Input.h \
    headers/InputNode.h \
    headers/Node.h \
    headers/Output.h \
    headers/BinaryFunction.h \
    headers/Parser.h \
    headers/PrintNode.h \
    headers/ReturNode.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
