#include "./headers/Node.h"

Node::Node(QWidget *parent) : QFrame(parent){
    setMaximumSize(150,150);
    setStyleSheet ("background-color: rgba(24, 135, 127, 1);"
                   "border: 1px solid rgba(205, 221, 63, 1);"
                   );
    this->setLayout(new QFormLayout());
    *(this->oldPos()) = this->pos();
}

Node::Node(QString _name,int ninputs,int noutputs,QWidget* parent) : Node(parent){

    QFormLayout* layout = static_cast<QFormLayout*>(this->layout());
    layout->setHorizontalSpacing(100);
    this->name = _name;
    this->nameLbl = new QLabel(name);

    this->nameLbl->setMaximumSize(80,20);
    //this->nameLbl->setStyleSheet("border: 0px solid white;");
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
    //Vlado mislim da u ovom delu koda treba da kriras vise izlaz akao sto si gore nisam htela da ti menjam klasu s obzirom d ami ovo sluzi za sta mi treba
    /*for(int i=0; i< noutputs; i++){
        Output* tmp = new Output();
        tmp->move(QPoint(10*i,0));
        this->layout()->addWidget(tmp);
        this->outputs.push_back(tmp);

    }*/
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

QPoint* Node::oldPos(){
    return &oldPos_;
}

QVector<Input*>* Node::getInputs(){
    return &(this->inputs);
}

void Node::mouseReleaseEvent(QMouseEvent *event){
    this->oldPos_ = this->pos();
}
