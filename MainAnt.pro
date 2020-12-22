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
    src/nodes/BodyNode.cpp \
    src/nodes/ConditionNode.cpp \
    src/CustomGraphicsView.cpp \
    src/nodes/ElseIfNode.cpp \
    src/nodes/ElseNode.cpp \
    src/nodes/EndOfStatement.cpp \
    src/nodes/ForInicializeNode.cpp \
    src/nodes/ForNode.cpp \
    src/nodes/FunctionNode.cpp \
    src/nodes/FunctionReturnNode.cpp \
    src/nodes/IfNode.cpp \
    src/nodes/IncrementNode.cpp \
    src/Input.cpp \
    src/nodes/InputNode.cpp \
    src/Node.cpp \
    src/Output.cpp \
    src/nodes/BinaryFunction.cpp \
    src/Parser.cpp \
    src/nodes/PrintNode.cpp \
    src/nodes/QueueNode.cpp \
    src/nodes/QueueOperations.cpp \
    src/nodes/ReturnNode.cpp \
    src/nodes/StackNode.cpp \
    src/nodes/StackOperations.cpp \
    src/nodes/VarNode.cpp \
    src/nodes/VariableReferenceNode.cpp \
    src/nodes/VectorNode.cpp \
    src/nodes/VectorOperations.cpp \
    src/nodes/WhileNode.cpp \
    src/SearchBar.cpp \
    src/nodes/StartNode.cpp\
    src/CustomLayout.cpp
    

HEADERS += \
    ./headers/mainwindow.h \
    ./headers/FunctionWindow.h \
    headers/BodyNode.h \
    headers/ConditionNode.h \
    headers/CustomGraphicsView.h \
    headers/ElseIfNode.h \
    headers/ElseNode.h \
    headers/EndOfStatement.h \
    headers/ForInicializeNode.h \
    headers/ForNode.h \
    headers/FunctionNode.h \
    headers/FunctionReturnNode.h \
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
