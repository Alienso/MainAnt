#include "./headers/BinaryFunction.h"

BinaryFunction::BinaryFunction(QString _name, int ninputs, int noutputs,QVector<QString> args, Parser *p_, QWidget *parent)
    :Node(_name, ninputs, noutputs, args, p, parent){
}

QString BinaryFunction::getCodeForNode()
{
    QString text="";
           if(this->getName()=="Binary_plus"){
               text.append("+");
           }
           else if(this->getName()=="Binary_minus"){
               text.append("-");
           }
           else if(this->getName()=="Binary_puta"){
               text.append("*");
           }
           else if(this->getName()=="Binary_manje"){
               text.append("<");
           }
           else if(this->getName()=="Binary_vece"){
               text.append(">");
           }
           else if(this->getName()=="Binary_i"){
               text.append("&&");
           }
           else if(this->getName()=="Binary_ili"){
               text.append("||");
           }
           else if(this->getName()=="Binary_jednako"){
               text.append("==");
           }
           else if(this->getName()=="Binary_manjeJednako"){
               text.append("<=");
           }
           else if(this->getName()=="Binary_veceJednako"){
               text.append(">=");
           }
       return text;
}

