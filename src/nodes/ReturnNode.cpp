#include "./headers/nodesHeaders/ReturNode.h"

ReturnNode::ReturnNode():Node("return", 1, 0)
{
    setMinimumSize(60,60);
    setStyleSheet ("background-color: rgba(0, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);"
                   "border-radius:5px;");
    setColors({'q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
}

QString ReturnNode::getCodeForNode()
{
    QString text = "return 0;\n}";

    return text;
}
