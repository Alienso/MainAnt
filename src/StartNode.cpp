#include "../headers/StartNode.h"

StartNode::StartNode():Node("StartNode", 0, 1, nullptr)
{
    setMinimumSize(60,60);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(0, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);");
}
