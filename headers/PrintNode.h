#ifndef PRINTNODE_H
#define PRINTNODE_H
#include <QString>
#include <QTextEdit>
#include <QFont>
#include "./headers/Node.h"

class PrintNode : public Node
{
public:
    PrintNode();
    void setOutText(QString inText);

};

#endif // PRINTNODE_H
