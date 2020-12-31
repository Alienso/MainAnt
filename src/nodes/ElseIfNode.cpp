#include "./headers/nodesHeaders/ElseIfNode.h"

ElseIfNode::ElseIfNode():Node("elseIf", 2, 2, {"flow", "condition"})
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(193, 66, 66, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px");
    setColors({'q','b','q','q'});

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
}

QString ElseIfNode::getCodeForNode()
{
    if (args[1]->toPlainText().compare("") == 0) return "#0";
    if (args[1]->toPlainText().compare("true",Qt::CaseInsensitive) == 0) return "true";
    if (args[1]->toPlainText().compare("false",Qt::CaseInsensitive) == 0) return "false";
    return args[1]->toPlainText();
}
