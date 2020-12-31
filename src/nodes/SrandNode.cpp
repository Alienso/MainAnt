#include "./headers/nodesHeaders/SrandNode.h"

SrandNode::SrandNode() : Node("srand",2,1){

    setStyleSheet ("background-color: rgba(0, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);"
                   "border-radius:5px;");

    setColors({'q','i','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
}

QString SrandNode::getCodeForNode()
{
    if (args[1]->toPlainText().compare("")!=0)
        return "srand(" + args[1]->toPlainText() + ");\n";
    return "srand(#1);\n";
}
