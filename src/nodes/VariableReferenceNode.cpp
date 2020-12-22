#include "../../headers/VariableReferenceNode.h"

VariableReferenceNode::VariableReferenceNode(QString _varName) : Node("VariableRef", 1, 1)
{
    this->refNameId = _varName;
    setMinimumSize(130,120);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(18, 125, 94, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());

    this->name = _varName;
    this->varName = new QTextEdit();
    this->varName->setText(_varName);
    this->varName->setReadOnly(true);

    layout->addWidget(this->varName);
}

//Saamo u slucaju variableREferenc enode zelimo da vracamo id node na koji referise jer je to zaprovo njegova uloga, tj njegov kod
QString VariableReferenceNode::getCodeForNode()
{
    return this->refNameId;
}

void VariableReferenceNode::setRefNameId(QString _refNameId)
{
    this->refNameId = _refNameId;
}

QString VariableReferenceNode::getRefNameId()
{
    return this->refNameId;
}


