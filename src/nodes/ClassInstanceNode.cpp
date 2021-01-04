#include "../../headers/nodesHeaders/ClassInstanceNode.h"

ClassInstanceNode::ClassInstanceNode(QString ClassName, QVector<QString> argTypes, QVector<QString> argNames)
    :Node(ClassName, argNames.size(), 1, argNames),
    newInstance(true)
  , ClassName(ClassName)
  , instanceName(nullptr)
  , visible(true)
{
    setMinimumSize(250,150);
    this->ClassInstance = true;
    QLineEdit* Iname = new QLineEdit(this);
    this->instanceName = Iname;
    Iname->setPlaceholderText("Enter the instance name");

    QRadioButton *alreadyExists = new QRadioButton("Var name already exist", this);
    QRadioButton* newInstance = new QRadioButton("New var instance", this);

    QButtonGroup* choice = new QButtonGroup(this);
    choice->addButton(newInstance, 1);
    choice->addButton(alreadyExists, 2);

    newInstance->setChecked(true);

    this->inputTypes["void"] = 'v';
    this->inputTypes["int"] = 'i';
    this->inputTypes["float"] = 'f';
    this->inputTypes["double"] = 'd';
    this->inputTypes["char"] = 'c';
    this->inputTypes["bool"] = 'c';
    this->inputTypes["std::string"] = 's';
    this->inputTypes["string"] = 's';

    QVector<QChar> colors = {'q'};
    for (int i=1;i<argTypes.size();i++)
        colors.append(this->inputTypes[argTypes[i]]);
    colors.append('q');
    setColors(colors);

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();

    connect(choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            [=](){
        int choosen = choice->checkedId();
        if(choosen == 1){
            this-> newInstance = true;
            this->visible = true;
        }else{
            this->newInstance = false;
            this->visible = false;
        }
    });

    int place = argTypes.size();
    layout->addWidget(Iname, place+1, 1);
    layout->addWidget(newInstance, place+2, 1);
    layout->addWidget(alreadyExists, place+3, 1);

}

QString ClassInstanceNode::getClassName() const
{
    return this->ClassName;
}

QString ClassInstanceNode::getCodeForNode()
{
    QString text = "";
    if(newInstance){
        text+=ClassName;
        text+="* ";
    }
    text+=instanceName->text();
    text+=" = ";
    text = text + "new " + ClassName + "(";

    return text;
}

QString ClassInstanceNode::getVarName() const
{
    return this->instanceName->text().trimmed();
}
