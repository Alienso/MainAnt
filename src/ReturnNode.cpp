#include "../headers/ReturNode.h"

ReturnNode::ReturnNode():Node("Retrn", 1, 0, nullptr)
{
    setMinimumSize(60,60);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(130, 236, 130, 1);");
}
