#ifndef REALLYBIGFUNCTIONSTHATYOUDONTNEEDTOSEE_H
#define REALLYBIGFUNCTIONSTHATYOUDONTNEEDTOSEE_H

#include <QList>
#include <QListWidgetItem>
#include <QVector>
#include <QMainWindow>
#include <QFormLayout>
#include <QtGui>
#include <QtCore>
#include <QFileDialog>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QPoint>
#include <QDebug>
#include <QList>

#include "./headers/BinaryFunction.h"
#include "./headers/Node.h"
#include "./headers/Parser.h"
#include "./headers/InputNode.h"
#include "./headers/PrintNode.h"
#include "./headers/ReturNode.h"
#include "./headers/StartNode.h"
#include "./headers/CustomGraphicsView.h"
#include "./headers/CustomLayout.h"
#include "./headers/SearchBar.h"
#include "./headers/IfNode.h"
#include "./headers/ConditionNode.h"
#include "./headers/ElseNode.h"
#include "./headers/BodyNode.h"
#include "./headers/ForNode.h"
#include "./headers/IncrementNode.h"
#include "./headers/ForInicializeNode.h"
#include "./headers/WhileNode.h"
#include "./headers/VarNode.h"
#include "./headers/VectorNode.h"
#include "./headers/VectorOperations.h"
#include "./headers/VariableReferenceNode.h"
#include "./headers/StackNode.h"
#include "./headers/StackOperations.h"
#include "./headers/QueueNode.h"
#include "./headers/QueueOperations.h"
#include "./headers/EndOfStatement.h"
#include "./headers/FunctionNode.h"

#include "./headers/mainwindow.h"
#include "./headers/FunctionWindow.h"

void putNode(QListWidgetItem* item,QMainWindow* w,QString s);
void functionsListInit(QMainWindow* w,QString s);

#endif // REALLYBIGFUNCTIONSTHATYOUDONTNEEDTOSEE_H
