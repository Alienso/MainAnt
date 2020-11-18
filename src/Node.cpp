#include "./headers/Node.h"

Node::Node(QWidget *parent) : QFrame(parent){
    setMaximumSize(150,150);
    setStyleSheet ("background-color: rgba(255, 255, 0, 1);");
    this->setLayout(new QFormLayout());
}

Node::Node(QString _name,int ninputs,int noutputs,QWidget* parent) : Node(parent){

    QFormLayout* layout = static_cast<QFormLayout*>(this->layout());
    layout->setHorizontalSpacing(100);
    this->name = _name;
    this->nameLbl = new QLabel(name);
    this->nameLbl->setMaximumSize(75,10);
    layout->insertRow(0,nameLbl);

    Output* o = new Output();
    o->addItem(""); //Must be used to be able to drag
    this->output = o;
    Input* tmp = new Input();
    layout->insertRow(1,tmp,o);

    for (int i=1;i<ninputs;i++){
        tmp = new Input();
        layout->insertRow(i+1,tmp);
        this->inputs.push_back(tmp);
    }
}

/*void node::mousePressEvent(QMouseEvent *event){

    this->move(event->pos());
    QString s(event->x() + "," + event->y());
    std::cout<<"P: "<<event->x() << "," << event->y() << std::endl;
    fflush(stdout);

}*/

void Node::mouseMoveEvent(QMouseEvent *event){


    if (childAt(event->pos())==nullptr){
        this->move(mapToParent(event->pos() - offset));
    }
    else {
        QFrame::mouseMoveEvent(event);
    }

}

void Node::mousePressEvent(QMouseEvent *event)
{
    offset = event->pos();
}
