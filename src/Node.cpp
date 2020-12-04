#include "./headers/Node.h"

Node::Node(QWidget *parent) : QFrame(parent)
{
    setMaximumSize(150,150);
    setStyleSheet ("background-color: rgba(24, 135, 127, 1);"
                   "border: 1px solid rgba(205, 221, 63, 1);"
                   );
    this->setLayout(new QGridLayout());
    *(this->getOldPos()) = this->pos();
}

Node::Node(QString _name,int ninputs,int noutputs,QVector<QString> args, Parser *p_,QWidget* parent) : Node(parent)
{
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->setHorizontalSpacing(2);
    layout->setVerticalSpacing(2);
    this->name = _name;
    this->nameLbl = new QLabel(name);
    if (args.length() == 0){
        args.resize(ninputs);
        for (int i=0;i<ninputs;i++)
            args[i] = "";
    }

    if (args.length() == 0){ //TMP RESENJE
        args.resize(1);
        args[0] = "";
    }

    this->nameLbl->setMaximumSize(80,20);
    //this->nameLbl->setStyleSheet("border: 0px solid white;");
    layout->addWidget(nameLbl,0,0,1,3);

    Output* o = new Output();
    o->addItem(""); //Must be used to be able to drag

    Input* tmp = new Input();
    QLabel* lbl = new QLabel(args[0]);
    lbl->setFixedSize(40,20);
    QTextEdit* txt = new QTextEdit();
    txt->setFixedSize(40,20);
    layout->addWidget(tmp,1,0);
    layout->addWidget(lbl,1,1,1,1);
    layout->addWidget(txt,1,2,1,1);
    layout->addWidget(o,1,3);
    this->inputs.push_back(tmp);
    this->output = o;

    for (int i=1;i<ninputs;i++){
        tmp = new Input();
        layout->addWidget(tmp,i+1,0);
        this->inputs.push_back(tmp);
    }
    this->p=p_;
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
                this->close();
                this->p->removeNode(this);
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

void Node::addParents(Node *parent)
{
    this->parentNodes.push_back(parent);
}

void Node::addChildren(Node *child)
{
    this->childNodes.push_back(child);
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

QString Node::getName()
{
    return this->name;
}

QVector<Node *> Node::getParentNodes()
{
    return parentNodes;
}


