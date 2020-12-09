#include "./headers/BinaryFunction.h"

BinaryFunction::BinaryFunction(QString _name, int ninputs, int noutputs,QVector<QString> args, Parser *p_, QWidget *parent)
    :Node(_name, ninputs, noutputs, args, p, parent){
}

QString BinaryFunction::getCodeForNode()
{
    QString text="";
           if(this->getName()=="plus"){
               text.append("+");
           }
           else if(this->getName()=="minus"){
               text.append("-");
           }
           else if(this->getName()=="puta"){
               text.append("*");
           }
           else if(this->getName()=="manje"){
               text.append("<");
           }
           else if(this->getName()=="vece"){
               text.append(">");
           }
           else if(this->getName()=="i"){
               text.append("&&");
           }
           else if(this->getName()=="ili"){
               text.append("||");
           }
           else if(this->getName()=="jednako"){
               text.append("==");
           }
           else if(this->getName()=="manje jednako"){
               text.append("<=");
           }
           else if(this->getName()=="vece jednako"){
               text.append(">=");
           }
       return text;
}

