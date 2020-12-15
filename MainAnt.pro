QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./src/main.cpp \
    ./src/mainwindow.cpp \
    ./src/FunctionWindow.cpp \
    src/BodyNode.cpp \
    src/ConditionNode.cpp \
    src/CustomGraphicsView.cpp \
    src/ElseNode.cpp \
    src/EndOfStatement.cpp \
    src/ForInicializeNode.cpp \
    src/ForNode.cpp \
    src/FunctionNode.cpp \
    src/IfNode.cpp \
    src/IncrementNode.cpp \
    src/Input.cpp \
    src/InputNode.cpp \
    src/Node.cpp \
    src/Output.cpp \
    src/BinaryFunction.cpp \
    src/Parser.cpp \
    src/PrintNode.cpp \
    src/QueueNode.cpp \
    src/QueueOperations.cpp \
    src/ReturnNode.cpp \
    src/StackNode.cpp \
    src/StackOperations.cpp \
    src/VarNode.cpp \
    src/VariableReferenceNode.cpp \
    src/VectorNode.cpp \
    src/VectorOperations.cpp \
    src/WhileNode.cpp \
    src/SearchBar.cpp \
    src/StartNode.cpp\
    src/CustomLayout.cpp
    

HEADERS += \
    ./headers/mainwindow.h \
    ./headers/FunctionWindow.h \
    headers/BodyNode.h \
    headers/ConditionNode.h \
    headers/CustomGraphicsView.h \
    headers/ElseNode.h \
    headers/EndOfStatement.h \
    headers/ForInicializeNode.h \
    headers/ForNode.h \
    headers/FunctionNode.h \
    headers/IfNode.h \
    headers/IncrementNode.h \
    headers/Input.h \
    headers/InputNode.h \
    headers/Node.h \
    headers/Output.h \
    headers/BinaryFunction.h \
    headers/Parser.h \
    headers/PrintNode.h \
    headers/QueueNode.h \
    headers/QueueOperations.h \
    headers/ReallyBigFunctionsThatYouDontNeedToSee.h \
    headers/ReturNode.h \
    headers/CustomLayout.h\
    headers/StackNode.h \
    headers/StackOperations.h \
    headers/VarNode.h \
    headers/VariableReferenceNode.h \
    headers/VectorNode.h \
    headers/VectorOperations.h \
    headers/WhileNode.h \
    headers/SearchBar.h \

FORMS += \
    FunctionWindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
