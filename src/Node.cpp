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

Node::Node(QString _name,int ninputs,int noutputs,QWidget* parent) : Node(parent)
{
    QFormLayout* layout = static_cast<QFormLayout*>(this->layout());
    layout->setHorizontalSpacing(100);
    this->name = _name;
    this->nameLbl = new QLabel(name);

    this->nameLbl->setMaximumSize(80,20);
    //this->nameLbl->setStyleSheet("border: 0px solid white;");
    layout->insertRow(0,nameLbl);

    Output* o = new Output();
    o->addItem(""); //Must be used to be able to drag

    Input* tmp = new Input();
    layout->insertRow(1,tmp,o);
    this->inputs.push_back(tmp);
    this->output = o;
    this->visited = false;

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
        myMenu.addAction("Hide");
        myMenu.addAction("Show");
        QAction *selectedItem=myMenu.exec(globalPos);

        if(selectedItem){
            if(selectedItem->toolTip()=="Delete"){
                qDebug()<<"Delete";
                this->close();
            }
            else if(selectedItem->toolTip()=="Hide"){
                qDebug()<< "Hide";

                Node *node=this;
                std::stack<Node *> stek;
                bool begining=true;

                while(!node->childNodes.empty() || !stek.empty() || begining==true){
                    begining=false;
                    int childNum=node->childNodes.size();
                    int i=0;
                    for(i; i<childNum; i++){

                        if(node->childNodes[i]->getVisitedHide()==false){
                            node->childNodes[i]->setVisitedHide(true);
                            node->childNodes[i]->hide();
                            stek.push(node->childNodes[i]);
                        }
                    }
                    node=stek.top();
                    stek.pop();
                    node->setVisitedHide(false);
                    node->hide();
                }
            } else if(selectedItem->toolTip()=="Show"){
                qDebug()<< "Show";
                Node *node=this;
                std::stack<Node *> stek;
                bool begining=true;

                while(!node->childNodes.empty() || !stek.empty() || begining==true){
                    begining=false;
                    int childNum=node->childNodes.size();
                    int i=0;
                    for(i; i<childNum; i++){

                        if(node->childNodes[i]->getVisitedHide()==false){
                            node->childNodes[i]->setVisitedHide(true);
                            node->childNodes[i]->show();

                            stek.push(node->childNodes[i]);
                        }
                    }
                    node=stek.top();
                    stek.pop();
                    node->setVisitedHide(false);
                    node->show();
                }
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

void Node::setVisitedHide(bool flag)
{
    this->visitedHide=flag;
}

void Node::addParents(Node *parent)
{
    this->parentNodes.push_back(parent);
}

void Node::addChildren(Node *child)
{
    this->childNodes.push_back(child);
}

QVector<Node*> Node::getChildren() const
{
    return this->childNodes;
}

QVector<Node *> Node::getParents() const
{
    return this->parentNodes;
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

void Node::setVisited(bool flag)
{
    this->visited = flag;
}

bool Node::getVisited()
{
    return this->visited;
}

bool Node::getVisitedHide()
{
    return this->visitedHide;
}

QString Node::getName()
{
    return this->name;
}



