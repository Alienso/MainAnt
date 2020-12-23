#include "./headers/nodesHeaders/EndOfStatement.h"

EndOfStatement::EndOfStatement() :Node("endofstatement", 1, 0, {"flow"})
{
    setMinimumSize(60,60);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(40, 11, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);");

}

QString EndOfStatement::getCodeForNode()
{
    return QString::fromStdString(";\n");
}
