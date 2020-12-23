#ifndef WHILENODE_H
#define WHILENODE_H

#include <QString>
#include <QTextEdit>
#include <QFont>

#include "./headers/Node.h"
#include "./headers/nodesHeaders/ConditionNode.h"
#include "./BodyNode.h"


class WhileNode : public Node
{
public:
    WhileNode();

    QString getCodeForNode() override;
};

#endif // WHILENODE_H
