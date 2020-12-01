#include "./headers/WhileNode.h"


WhileNode::WhileNode():
    Node("while",2,1, nullptr)
{
    setMinimumSize(100,100);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(58, 95, 134, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);");
}

QString WhileNode::getCodeForNode()
{
    QString text="while";
    //ovde treba da dodje Condtion Node koji je prikljucen za input
    ConditionNode *c=new ConditionNode();
    QString condition=c->getCodeForNode();

    text.append("("+ condition +")");

    //ovde treba da dodje Body Node koji je prikljucen za output
    BodyNode *b=new BodyNode();
    QString body=b->getCodeForNode();

    text.append("{\n"+ body +"\n}\n");

    return text;
}
