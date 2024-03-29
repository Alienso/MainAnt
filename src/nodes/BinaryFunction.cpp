#include "./headers/nodesHeaders/BinaryFunction.h"

BinaryFunction::BinaryFunction(QString _name, int ninputs, int noutputs)
    :Node(_name, ninputs, noutputs){
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
        setColors({'q','n','n','b'});
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
        setColors({'q','n','n','b'});
    }
    else if(this->getName()=="Binary_manjeJednako"){
        setColors({'q','n','n','b'});
    }
    else if(this->getName()=="Binary_veceJednako"){
        setColors({'q','n','n','b'});
    }
    else if(this->getName()=="Binary_mod"){
        setColors({'q','n','n','i'});
    }
}

QString BinaryFunction::getCodeForNode()
{
    QString text="#0(";
    QString arg1 = this->args[1]->toPlainText();
    QString arg2 = this->args[2]->toPlainText();
    if (arg1.compare("") == 0){
        text.append("#1");
        std::cout<<"Nema prvog arga\n";
    }
    else text.append(arg1);
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
           else if(this->getName()=="Binary_mod"){
               text.append("%");
           }
       if (arg2.compare("") == 0){
           text.append("#2)");
           std::cout<<"Nema drugog arga\n";
       }
       else text.append(arg2 + ")");
       return text;
}

