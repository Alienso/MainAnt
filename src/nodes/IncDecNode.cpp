#include "./headers/nodesHeaders/IncDecNode.h"

IncDecNode::IncDecNode() : Node("incdec", 1, 1)
{
    setMinimumSize(220,170);
    setStyleSheet ("background-color: rgba(48, 125, 44, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");

    setColors({'q','q'});

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->operand = new QLineEdit();
    const QString* placeHolderVarName = new QString("Enter var name...");
    this->operand->setPlaceholderText(*placeHolderVarName);

    this->operatorType = new QComboBox();
    this->operatorType->addItem("++");
    this->operatorType->addItem("--");

    this->prePostGroup = new QGroupBox();

    this->isPre = new QRadioButton(tr("&Pre"));
    this->isPost = new QRadioButton(tr("&Post"));

    this->isPre->setChecked(true);

    QHBoxLayout* layoutBox = new QHBoxLayout();
    layoutBox->addWidget(this->isPre);
    layoutBox->addWidget(this->isPost);

    this->prePostGroup->setLayout(layoutBox);
    this->prePostGroup->setFlat(true);

    layout->addWidget(this->operatorType, 3 ,0);
    layout->addWidget(this->prePostGroup, 4, 0);
    layout->addWidget(this->operand, 5 ,0);

}

QString IncDecNode::getCodeForNode()
{
    QString text = "";

    if(this->isPre->isChecked()){
        text += this->operatorType->currentText();
        text += this->operand->text();
    }else if(this->isPost->isChecked()){
        text += this->operand->text();
        text += this->operatorType->currentText();
    }

    return text;
}
