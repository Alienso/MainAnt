#include "./headers/BinaryFunction.h"

BinaryFunction::BinaryFunction(QString _name, int ninputs, int noutputs,QVector<QString> args, Parser *p_, QWidget *parent)
    :Node(_name, ninputs, noutputs, args, p, parent){
}

QString BinaryFunction::getCodeForNode()
{
    QString text="";
       if(this->op1 != nullptr && this->op2 != nullptr){
           if(this->getName()=="plus"){
               text.append(this->op1);
               text.append(" + ");
               text.append(this->op2);
               text.append(";");
           }
           else if(this->getName()=="minus"){
               text.append(this->op1);
               text.append(" - ");
               text.append(this->op2);
               text.append(";");
           }
           else if(this->getName()=="puta"){
               text.append(this->op1);
               text.append(" * ");
               text.append(this->op2);
               text.append(";");
           }
           else if(this->getName()=="manje"){
               text.append(this->op1);
               text.append(" < ");
               text.append(this->op2);
               text.append(";");
           }
       }
       return text;
}
//ova fja ce se obrisati, ovo je samo da mogu da proverim da li radi posto nemam parser
/*
void BinaryFunction::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton){
        QPoint globalPos=this->mapToGlobal(event->pos());
        QMenu myMenu;
        myMenu.addAction("Pokreni");
        QAction *selectedItem=myMenu.exec(globalPos);

        if(selectedItem){
            if(selectedItem->toolTip()=="Pokreni"){
                qDebug()<<"Pokreni";
                auto inputi=this->getParentNodes();

                InputNode *inp1=static_cast<InputNode*>(inputi[0]);
                InputNode *inp2=static_cast<InputNode*>(inputi[1]);
                qDebug()<<inp1->getText();
                qDebug()<<inp2->getText();
            }
        }
    }
}*/
void BinaryFunction::setParameters(InputNode *op1_, InputNode *op2_)
{
    this->op1=*op1_->getText();
    this->op2=*op1_->getText();
}
