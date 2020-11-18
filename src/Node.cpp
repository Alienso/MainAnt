#include "./headers/Node.h"

Node::Node(QWidget *parent) : QFrame(parent){
    setMinimumSize(150,150);
    setMaximumSize(150,150);
    setStyleSheet ("background-color: rgba(255, 255, 0, 1);");
    this->name = "";
}

Node::Node(QWidget* parent,int ninputs) : Node(parent,ninputs,0){
    Output* o = new Output();
    o->addItem("");
    this->layout()->addWidget(o);
    this->output = o;
}

Node::Node(QWidget* parent,int ninputs,int noutputs) : Node(parent){
    this->setLayout(new QFormLayout());
    for (int i=0;i<ninputs;i++){
        Input* tmp = new Input();
        tmp->move(QPoint(10*i,0));
        this->layout()->addWidget(tmp);
        this->inputs.push_back(tmp);
    }
}

//Do not use
Node::Node(QString _name,QWidget* parent,int ninputs,int noutputs) : Node(parent,ninputs,noutputs){
    this->name = _name;
    this->nameLbl = new QLabel(name);
    this->nameLbl->move(100,0);
    layout()->addWidget(nameLbl);
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
