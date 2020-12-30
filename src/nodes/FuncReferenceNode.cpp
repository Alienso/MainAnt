#include "../../headers/nodesHeaders/FuncReferenceNode.h"

FuncReferenceNode::FuncReferenceNode(QString retVal, QString funcName, QVector<QString>& funcTypes, QVector<QString>& funcNames)
    :Node(funcName, funcNames.size(), 1, funcNames)
{
    this->name = funcName;
    this->retVal = retVal;
    this->funcRef = true;
}

//Vracamo samo ime funkcije ostalo ce parser da odradi
QString FuncReferenceNode::getCodeForNode()
{
    return this->name + "(";
}
