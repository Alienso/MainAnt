#include "./headers/WhileNode.h"


WhileNode::WhileNode():
    Node("While",2,1, nullptr)
{
    setMinimumSize(100,100);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(58, 95, 134, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);");
}

QString WhileNode::getCodeForNode()
{
    QString text = "";

    return text;

}
