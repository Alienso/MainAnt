#include "./headers/nodesHeaders/FunctionReturnNode.h"

FunctionReturnNode::FunctionReturnNode() : Node("FunctionReturn", 1, 0), isVoid(false), edit(nullptr)
{
    setMinimumSize(180,180);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(0, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);"
                   "border-radius:5px;");

    setColors({'q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());

    QButtonGroup *choice = new QButtonGroup(this);
    QRadioButton*  returnValueIsVoid = new QRadioButton("Return is void", this);
    QRadioButton*  returnValueIsNotVoid = new QRadioButton("Return is not void", this);

    choice->addButton(returnValueIsVoid, 1);
    choice->addButton(returnValueIsNotVoid, 2);

    layout->addWidget(returnValueIsVoid, 3, 1);
    layout->addWidget(returnValueIsNotVoid, 4, 1);
    connect(choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            [=](){
        int choosen = choice->checkedId();
        if(choosen == 1){
            if(edit != nullptr){
                edit->deleteLater();            }
            this->isVoid = true;
        }
        else if(choosen == 2){
            this->isVoid = false;
            QLineEdit* enterReturnValue = new QLineEdit(this);
            enterReturnValue->setPlaceholderText("Enter the value or var");
            this->edit = enterReturnValue;

            QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
            layout->addWidget(edit,5, 1);
        }
    });

}

QString FunctionReturnNode::getCodeForNode()
{
    QString text = "";
    if (this->isVoid){
        text.append("return;\n}");
    }else{
        QString returnVale = edit->text();
        text.append("return ");
        text.append(returnVale);
        text.append(";\n}");

    }
    return text;
}


