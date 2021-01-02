#ifndef VARIABLEREFERENCENODE_H
#define VARIABLEREFERENCENODE_H


#include <QTextEdit>

#include "./headers/Node.h"

class VariableReferenceNode : public Node
{
public:
    VariableReferenceNode(QString _varName, QString _redNameId);
    QString name;
    QTextEdit* varName;

    QString getCodeForNode() override;
    void setRefNameId(QString _refNameId);
    QString getRefNameId();

private:
    QString refNameId;
};

#endif // VARIABLEREFERENCENODE_H
