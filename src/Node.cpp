#include "./headers/Node.h"

Node::Node(QWidget *parent) : QFrame(parent)
{
    setMaximumSize(150,150);
    setStyleSheet ("background-color: rgba(24, 135, 127, 1);"
                   "border: 1px solid rgba(205, 221, 63, 1);"
                   );
    this->setLayout(new QFormLayout());
    *(this->getOldPos()) = this->pos();
}

Node::Node(QString _name,int ninputs,int noutputs, QString _code,bool _hasFlowControl,QWidget* parent) : Node(parent)
{
    QFormLayout* layout = static_cast<QFormLayout*>(this->layout());
    layout->setHorizontalSpacing(100);
    this->name = _name;
    this->nameLbl = new QLabel(name);
    this->hasFlowControl = _hasFlowControl;
    this->code = _code;

    this->nameLbl->setMaximumSize(80,20);
    //this->nameLbl->setStyleSheet("border: 0px solid white;");
    int n = 0;
    int wasInLoop = 0;

    //Ukoliko su nam potrebni cvorovi za obilazenje grafa (nrp ako naidjemo na if)
    if (hasFlowControl){
        Output* o = new Output();
        Input* tmp = new Input();
        o->addItem(""); //Must be used to be able to drag
        layout->insertRow(0,tmp,o);
        this->inputs.push_back(tmp);
        this->outputs.push_back(o);
        n = 1;
    }

    //Label imena
    layout->insertRow(n,nameLbl);

    //Pravljenje inputa i outputa
    for (int i=0;i < std::min(ninputs,noutputs);i++){

        Output* o = new Output();
        Input* tmp = new Input();
        o->addItem(""); //Must be used to be able to drag
        layout->insertRow(i+1+hasFlowControl,tmp,o);
        this->inputs.push_back(tmp);
        this->outputs.push_back(o);
        n = i;
        wasInLoop = 1;
    }
    if (wasInLoop)
        n++;

    for (int i=n;i<std::max(ninputs,noutputs);i++){
        if (ninputs == noutputs){
            Input* tmp = new Input();
            Output* o = new Output();
            o->addItem("");
            layout->insertRow(i+1+hasFlowControl,tmp,o);
            this->inputs.push_back(tmp);
            this->outputs.push_back(o);
            continue;
        }

        if (noutputs>ninputs){
            Output* tmp = new Output();
            tmp->addItem("");
            layout->insertRow(i+1+hasFlowControl,nullptr,tmp);
            this->outputs.push_back(tmp);
            continue;
        }
        if (ninputs>noutputs){
            Input* tmp = new Input();
            layout->insertRow(i+1+hasFlowControl,tmp);
            this->inputs.push_back(tmp);
            continue;
        }
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


void Node::mouseMoveEvent(QMouseEvent *event)
{
    if (childAt(event->pos())==nullptr){
        this->move(mapToParent(event->pos() - offset));
    }
    else {
        QFrame::mouseMoveEvent(event);
    }
    this->oldPos_ = this->pos();
}

void Node::mousePressEvent(QMouseEvent *event)
{
    offset = event->pos();
    if(event->button()==Qt::RightButton){
        QPoint globalPos=this->mapToGlobal(event->pos());
        QMenu myMenu;
        myMenu.addAction("Delete");
        QAction *selectedItem=myMenu.exec(globalPos);

        if(selectedItem){
            if(selectedItem->toolTip()=="Delete"){
                qDebug()<<"Delete";
            }
        }

        /*CustomGraphicsView* stagingArea = static_cast<CustomGraphicsView*>(this->parent());
        QVector<Node*>* nodesVector = stagingArea->getNodes();

        for(int i=0; i< nodesVector->length(); i++)
        {
            if((*nodesVector)[i]->getCodeForNode() == this->getCodeForNode())
            {
             QDebug() << this->getCodeForNode();
             (*nodesVector).erase(i);
            }
       }
       */

        //this->deleteLater();
    }
}
void Node::setNodeId(QString nodeId)
{
    this->nodeId = nodeId;
}

QPoint* Node::getOldPos(){
    return &oldPos_;
}

QVector<Input*>* Node::getInputs(){
    return &(this->inputs);
}

QString Node::getCodeForNode()
{

}

QString Node::getNodeId()
{
    return this->nodeId;
}


