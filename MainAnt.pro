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
    ./src/ClassWindow.cpp \
    src/nodes/AssignNode.cpp \
    src/nodes/BodyNode.cpp \
    src/nodes/BreakNode.cpp \
    src/nodes/ClassField.cpp \
    src/nodes/ClassInstanceNode.cpp \
    src/nodes/ClassNode.cpp \
    src/nodes/ConditionNode.cpp \
    src/CustomGraphicsView.cpp \
    src/nodes/ContinueNode.cpp \
    src/nodes/ElseIfNode.cpp \
    src/nodes/ElseNode.cpp \
    src/nodes/EndOfStatement.cpp \
    src/nodes/ForInicializeNode.cpp \
    src/nodes/ForNode.cpp \
    src/nodes/FuncReferenceNode.cpp \
    src/nodes/FunctionNode.cpp \
    src/nodes/FunctionReturnNode.cpp \
    src/nodes/IfNode.cpp \
    src/nodes/IncDecNode.cpp \
    src/nodes/IncrementNode.cpp \
    src/Input.cpp \
    src/nodes/InputNode.cpp \
    src/Node.cpp \
    src/Output.cpp \
    src/nodes/BinaryFunction.cpp \
    src/Parser.cpp \
    src/nodes/MapNode.cpp \
    src/nodes/MapOperations.cpp \
    src/nodes/MethodNode.cpp \
    src/nodes/PrintNode.cpp \
    src/nodes/QueueNode.cpp \
    src/nodes/QueueOperations.cpp \
    src/nodes/ReferenceNode.cpp \
    src/nodes/ReturnNode.cpp \
    src/nodes/SrandNode.cpp \
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
    ./headers/ClassWindow.h \
    headers/nodesHeaders/AssignNode.h \
    headers/nodesHeaders/BodyNode.h \
    headers/nodesHeaders/BreakNode.h \
    headers/nodesHeaders/ClassField.h \
    headers/nodesHeaders/ClassInstanceNode.h \
    headers/nodesHeaders/ClassNode.h \
    headers/nodesHeaders/ConditionNode.h \
    headers/CustomGraphicsView.h \
    headers/nodesHeaders/ContinueNode.h \
    headers/nodesHeaders/ElseIfNode.h \
    headers/nodesHeaders/ElseNode.h \
    headers/nodesHeaders/EndOfStatement.h \
    headers/nodesHeaders/ForInicializeNode.h \
    headers/nodesHeaders/ForNode.h \
    headers/nodesHeaders/FuncReferenceNode.h \
    headers/nodesHeaders/FunctionNode.h \
    headers/nodesHeaders/FunctionReturnNode.h \
    headers/nodesHeaders/IfNode.h \
    headers/nodesHeaders/IncDecNode.h \
    headers/nodesHeaders/IncrementNode.h \
    headers/Input.h \
    headers/nodesHeaders/InputNode.h \
    headers/Node.h \
    headers/Output.h \
    headers/nodesHeaders/BinaryFunction.h \
    headers/Parser.h \
    headers/nodesHeaders/MapNode.h \
    headers/nodesHeaders/MapOperations.h \
    headers/nodesHeaders/MethodNode.h \
    headers/nodesHeaders/PrintNode.h \
    headers/nodesHeaders/QueueNode.h \
    headers/nodesHeaders/QueueOperations.h \
    headers/ReallyBigFunctionsThatYouDontNeedToSee.h \
    headers/nodesHeaders/ReferenceNode.h \
    headers/nodesHeaders/ReturNode.h \
    headers/CustomLayout.h\
    headers/nodesHeaders/StackNode.h \
    headers/nodesHeaders/StackOperations.h \
    headers/nodesHeaders/VarNode.h \
    headers/nodesHeaders/VariableReferenceNode.h \
    headers/nodesHeaders/VectorNode.h \
    headers/nodesHeaders/VectorOperations.h \
    headers/nodesHeaders/WhileNode.h \
    headers/SearchBar.h \
    headers/nodesHeaders/SrandNode.h

FORMS += \
    forms/ClassWindow.ui \
    forms/FunctionWindow.ui \
    forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
