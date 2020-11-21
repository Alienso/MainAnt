#include "./headers/CustomGraphicsView.h"

CustomGraphicsView::CustomGraphicsView(QWidget* parent){
    nodes = new QVector<Node*>();
}

void CustomGraphicsView::paintEvent(QPaintEvent* e){

    QPainter painter(viewport());
    QPen pen(Qt::red);
    pen.setWidth(10);

    painter.setPen(pen);
    repositionNodes();

    //Povezivanje Node-ova TODO
    QPoint a,b;
    for (Node* n : *nodes){
        for (Input* i : *(n->getInputs())){
            if (i->getPrevious() != nullptr){
                a = n->mapToParent(i->pos());
                b = (i->getPrevious()->parentWidget())->mapToParent(i->getPrevious()->pos());
                painter.drawLine(a,b);
            }
        }
    }
    update();

}

//Vraca nodeove nazad na svoje mesto nakon dodavanja novog node-a
//TODO
void CustomGraphicsView::repositionNodes(){

    for (Node* n : *nodes){
        if (n->pos() != *(n->oldPos()))
            n->move(n->oldPos()->x(),n->oldPos()->y());
    }
}

QVector<Node*>* CustomGraphicsView::getNodes(){
    return nodes;
}
