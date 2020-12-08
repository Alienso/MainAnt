#include "./headers/ReturNode.h"

ReturnNode::ReturnNode():Node("return", 1, 0)
{
    setMinimumSize(60,60);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(0, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);");
}

QString ReturnNode::getCodeForNode()
{
    QString text = "return 0;\n}";

    return text;
}
