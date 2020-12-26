#include "./headers/nodesHeaders/StartNode.h"

StartNode::StartNode():Node("StartNode", 0, 1)
{
    setMaximumWidth(100);
    setStyleSheet ("background-color: rgba(0, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);"
                   "border-radius:5px;");
    setColors({'q'});
}

QString StartNode::getCodeForNode()
{
    QString text = "int main(){\n";

    return text;
}

void StartNode::run() const
{
    //Ovo je specijalan tip noda koji samo oznacava pocetakprograma
    return;
}



