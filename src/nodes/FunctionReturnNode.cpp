#include "./headers/nodesHeaders/FunctionReturnNode.h"

FunctionReturnNode::FunctionReturnNode() : Node("FunctionReturn", 1, 0),
    isVoid(true),
    edit(nullptr),
    consstructor(false),
    earlyReturn(false),
    returnCode(nullptr)
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
    QRadioButton* con = new QRadioButton("Creating consructor", this);
    QRadioButton* eReturn = new QRadioButton("Early end to my function", this);
    returnValueIsVoid->setChecked(true);

    choice->addButton(returnValueIsVoid, 1);
    choice->addButton(returnValueIsNotVoid, 2);
    choice->addButton(con, 3);
    choice->addButton(eReturn, 4);

    layout->addWidget(returnValueIsVoid, 3, 1);
    layout->addWidget(returnValueIsNotVoid, 4, 1);
    layout->addWidget(con, 5, 1);
    layout->addWidget(eReturn, 6, 1);
    connect(choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            [=](){
        int choosen = choice->checkedId();
        if(choosen == 1){
            if(edit != nullptr){
                edit->deleteLater();
                edit= nullptr;
            }else if(returnCode != nullptr){
                returnCode->deleteLater();
                returnCode = nullptr;
            }
            this->isVoid = true;
            this->consstructor = false;
            this->earlyReturn = false;
        }
        else if(choosen == 2){
            if(returnCode != nullptr){
                returnCode->deleteLater();
                returnCode = nullptr;
           }
            this->isVoid = false;
            this->consstructor = false;
            this->earlyReturn = false;
            QLineEdit* enterReturnValue = new QLineEdit(this);
            enterReturnValue->setPlaceholderText("Enter the value or var");
            this->edit = enterReturnValue;

            QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
            layout->addWidget(edit,5, 1);
        }else if(choosen == 3){
            if(edit != nullptr){
                edit->deleteLater();
                edit= nullptr;
            }else if(returnCode != nullptr){
                returnCode->deleteLater();
                returnCode = nullptr;
            }
            this->isVoid = false;
            this->earlyReturn = false;
            this->consstructor = true;
        }else if(choosen == 4){
            if(edit != nullptr){
                edit->deleteLater();
                edit= nullptr;
            }
            this->isVoid = false;
            this->consstructor = false;
            this->earlyReturn = true;

            QLineEdit* enterReturnValue = new QLineEdit(this);
            enterReturnValue->setPlaceholderText("Enter return code/var");
            this->returnCode = enterReturnValue;

            QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
            layout->addWidget(returnCode,5, 1);
            QMessageBox msgBox;
            msgBox.setText("In order to properly end you program you neeed to enter the return value or var name");
            msgBox.exec();


        }
    });

}

QString FunctionReturnNode::getCodeForNode()
{
    QString text = "";
    if (this->isVoid){
        text.append("return;\n}");
    }else if(this->consstructor){
        text.append("}");
    }else if(this->earlyReturn){
        QString text = "return ";
        QString retCode = this->returnCode->text();
        text+= retCode;
        text+=";\n";
        return text;
    }else{
        QString returnVale = edit->text();
        text.append("return ");
        text.append(returnVale);
        text.append(";\n}");

    }
    return text;
}


