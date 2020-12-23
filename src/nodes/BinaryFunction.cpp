#include "./headers/nodesHeaders/BinaryFunction.h"

BinaryFunction::BinaryFunction(QString _name, int ninputs, int noutputs,QVector<QString> args, Parser *p_, QWidget *parent)
    :Node(_name, ninputs, noutputs, args, p_, parent){
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
    if(this->getName()=="Binary_plus"){
        setColors({'q','n','n','n'});
    }
    else if(this->getName()=="Binary_minus"){
        setColors({'q','n','n','n'});
    }
    else if(this->getName()=="Binary_puta"){
        setColors({'q','n','n','n'});
    }
    else if(this->getName()=="Binary_podeljeno"){
        setColors({'q','n','n','n'});
    }
    else if(this->getName()=="Binary_manje"){
        setColors({'q','n','n','n'});
    }
    else if(this->getName()=="Binary_vece"){
        setColors({'q','n','n','b'});
    }
    else if(this->getName()=="Binary_i"){
        setColors({'q','b','b','b'});
    }
    else if(this->getName()=="Binary_ili"){
        setColors({'q','b','b','b'});
    }
    else if(this->getName()=="Binary_jednako"){
        setColors({'q','n','n','n'});
    }
    else if(this->getName()=="Binary_manjeJednako"){
        setColors({'q','n','n','b'});
    }
    else if(this->getName()=="Binary_veceJednako"){
        setColors({'q','n','n','b'});
    }
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
           else if(this->getName()=="Binary_podeljeno"){
               text.append("/");
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

