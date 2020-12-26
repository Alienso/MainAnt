#include "./headers/nodesHeaders/EndOfStatement.h"

EndOfStatement::EndOfStatement() :Node("EndOfStat", 1, 1)
{
    setMinimumSize(60,60);
    setMaximumWidth(100);
    setStyleSheet ("background-color: rgba(90, 11, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);"
                   "border-radius:5px;");
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
    setColors({'q','q'});

}

QString EndOfStatement::getCodeForNode()
{
    return QString::fromStdString(";\n");
}
