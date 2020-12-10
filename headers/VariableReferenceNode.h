#ifndef VARIABLEREFERENCENODE_H
#define VARIABLEREFERENCENODE_H


#include <QTextEdit>

#include "./headers/Node.h"

class VariableReferenceNode : public Node
{
public:
    VariableReferenceNode(QString _varName);
    QString name;
    QTextEdit* varName;

    QString getCodeForNode() override;
};

#endif // VARIABLEREFERENCENODE_H
