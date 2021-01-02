#include "./headers/nodesHeaders/ReturNode.h"

ReturnNode::ReturnNode():Node("return", 1, 0), earlyEnd(false), returncCode(nullptr)
{
    setMinimumSize(150,170);
    setStyleSheet ("background-color: rgba(0, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);"
                   "border-radius:5px;");
    setColors({'q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    QRadioButton* eReturn= new QRadioButton("Early return", this);
    QRadioButton* classicReturn = new QRadioButton("End of main return", this);

    QButtonGroup *choice = new QButtonGroup(this);
    choice->addButton(classicReturn, 1);
    choice->addButton(eReturn, 2);
    classicReturn->setChecked(true);

    connect(choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            [=](){
        int choosen = choice->checkedId();
        if(choosen == 1){
            if(this->returncCode != nullptr){
                this->returncCode->deleteLater();
                this->returncCode = nullptr;
            }
            earlyEnd = false;
        }else if(choosen == 2){
            earlyEnd = true;
            QLineEdit* enterRetCode = new QLineEdit(this);
            enterRetCode->setPlaceholderText("enter return code");
            this->returncCode = enterRetCode;
            Node* parent = static_cast<Node*>(choice->parent());
            QGridLayout* layout = static_cast<QGridLayout*>(parent->layout());
            layout->addWidget(returncCode, 4, 0);
            QMessageBox msgBox;
            msgBox.setText("In order to properly end you program you neeed to enter the return code 1/0 in line edit");
            msgBox.exec();


        }
    });
    layout->addWidget(classicReturn, 2, 0);
    layout->addWidget(eReturn, 3, 0);



}

QString ReturnNode::getCodeForNode()
{
    if(earlyEnd){
        QString text = "return ";
        QString retCode = returncCode->text();
        text+= retCode;
        text+=";\n";
        return text;
    }
    QString text = "getchar();\nreturn 0;\n";

    return text;
}
