#ifndef FUNCREFERENCENODE_H
#define FUNCREFERENCENODE_H

#include "../Node.h"

class FuncReferenceNode : public Node
{
private:
    QString retVal;
    QMap<QString,QChar> inputTypes;
public:
    FuncReferenceNode(QString retVal, QString funcName, QVector<QString>& funcTypes, QVector<QString>& funcNames);
    QString getCodeForNode() override;
};

#endif // FUNCREFERENCENODE_H
