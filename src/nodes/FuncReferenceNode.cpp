#include "../../headers/nodesHeaders/FuncReferenceNode.h"

FuncReferenceNode::FuncReferenceNode(QString retVal, QString funcName, QVector<QString>& funcTypes, QVector<QString>& funcNames)
{
    this->name = funcName;
    this->retVal = retVal;
    int inputNumber = funcNames.size();
    Node(this->name, inputNumber , 1, funcNames);
}

//Vracamo samo ime funkcije ostalo ce parser da odradi
QString FuncReferenceNode::getCodeForNode()
{
    return this->name;
}
