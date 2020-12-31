#include "../../headers/nodesHeaders/FuncReferenceNode.h"

FuncReferenceNode::FuncReferenceNode(QString retVal, QString funcName, QVector<QString>& funcTypes, QVector<QString>& funcNames)
    :Node(funcName, funcNames.size(), 1, funcNames)
{
    this->inputTypes["void"] = 'v';
    this->inputTypes["int"] = 'i';
    this->inputTypes["float"] = 'f';
    this->inputTypes["double"] = 'd';
    this->inputTypes["char"] = 'c';
    this->inputTypes["bool"] = 'c';
    this->inputTypes["std::string"] = 's';
    this->inputTypes["string"] = 's';

    this->name = funcName;
    this->retVal = retVal;
    this->funcRef = true;
    QVector<QChar> colors = {'q'};
    for (int i=1;i<funcTypes.size();i++)
        colors.append(this->inputTypes[funcTypes[i]]);
    colors.append(this->inputTypes[retVal]);
    setColors(colors);
}

//Vracamo samo ime funkcije ostalo ce parser da odradi
QString FuncReferenceNode::getCodeForNode()
{
    return this->name + "(";
}
