#include "../headers/IncrementNode.h"

IncrementNode::IncrementNode() : Node("IncrementNode", 1, 1, nullptr)
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(197, 89, 86, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");
}

QString IncrementNode::getCodeForNode()
{
    //TODO mora da se napise kode koji ce da vraca cvor Increment node
    QString text = "#include<isotream>\n#include<string>\n\nint main(){\n";
    qDebug()<<"IncremnetNode";
    return text;
}
