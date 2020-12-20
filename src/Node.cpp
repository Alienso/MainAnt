#include "./headers/Node.h"

Node::Node(QWidget *parent) : QFrame(parent)
{
    setMaximumSize(150,150);
    setStyleSheet ("background-color: rgba(24, 135, 127, 1);"
                   "border: 1px solid rgba(205, 221, 63, 1);"
                   );
    this->setLayout(new QGridLayout());
    *(this->getOldPos()) = this->pos();
    colors['i'] = "border-width: 2px;border-color: rgba(0, 194, 255, 1);border-radius: 10px;"; //int long
    colors['n'] = "border-width: 2px;border-color: rgba(173, 91, 219, 1);border-radius: 10px;"; //broj
    colors['f'] = "border-width: 2px;border-color: rgba(141, 233, 50, 1);border-radius: 10px;"; //float double
    colors['b'] = "border-width: 2px;border-color: rgba(255, 2, 116, 1);border-radius: 10px;"; //bool
    colors['s'] = "border-width: 2px;border-color: rgba(255, 156, 57, 1);border-radius: 10px;"; //string
    colors['c'] = "border-width: 2px;border-color: rgba(255, 104, 107, 1);border-radius: 10px;"; //char
    colors['q'] = "border-width: 2px;border-color: rgba(65, 247, 201, 1);border-radius: 10px;"; //kontrola toka
}

//TODO QT resetuje velicinu fonta u textEditu kada se sve izbrise
Node::Node(QString _name,int ninputs,int noutputs,QVector<QString> args, Parser *p_,QWidget* parent) : Node(parent)
{
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->setHorizontalSpacing(2);
    layout->setVerticalSpacing(5);
    this->setMaximumSize(150, ninputs>noutputs ? 27*(ninputs+1) : 27*(noutputs+1));
    this->p=p_;
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

    this->nameLbl->setMaximumSize(100,20);
    layout->addWidget(nameLbl,0,0,1,3);
    QFont f( "Arial", 6);
    int n = 0;
    for (int i=0;i < std::min(ninputs,noutputs);i++,n++){

        Output* o = new Output();
        Input* tmp = new Input();
        layout->addWidget(tmp,i+1,0);
        layout->addWidget(o,i+1,3);
        this->inputs.push_back(tmp);
        this->outputs.push_back(o);

        if (args[i].compare("") != 0){
            QLabel* lbl = new QLabel(args[i]);
            lbl->setFixedSize(40,20);
            lbl->setFont(f);
            QTextEdit* txt = new QTextEdit();
            txt->setFixedSize(40,20);
            txt->setFontPointSize(6);
            layout->addWidget(lbl,i+1,1,1,1);
            layout->addWidget(txt,i+1,2,1,1);
        }
        else {
            QTextEdit* txt = new QTextEdit();
            txt->setFixedSize(40,20);
            txt->setFontPointSize(6);
            layout->addWidget(txt,i+1,1);
        }

    }
    for (int i=n;i<std::max(ninputs,noutputs);i++){
        if (ninputs == noutputs){
            Output* o = new Output();
            Input* tmp = new Input();
            layout->addWidget(tmp,i+1,0);
            layout->addWidget(o,i+1,3);
            this->inputs.push_back(tmp);
            this->outputs.push_back(o);

            if (args[i].compare("") != 0){
                QLabel* lbl = new QLabel(args[i]);
                lbl->setFixedSize(40,20);
                lbl->setFont(f);
                QTextEdit* txt = new QTextEdit();
                txt->setFontPointSize(6);
                txt->setFixedSize(40,20);
                layout->addWidget(lbl,i+1,1,1,1);
                layout->addWidget(txt,i+1,2,1,1);
            }
            else {
                QTextEdit* txt = new QTextEdit();
                txt->setFixedSize(40,20);
                txt->setFontPointSize(6);
                layout->addWidget(txt,i+1,1);
            }
            continue;
        }

        if (noutputs>ninputs){
            Output* tmp = new Output();
            this->outputs.push_back(tmp);
            layout->addWidget(tmp,i+1,3);
            continue;
        }
        if (ninputs>noutputs){
            Input* tmp = new Input();
            layout->addWidget(tmp,i+1,0);
            this->inputs.push_back(tmp);

            if (args[i].compare("") != 0){
                QLabel* lbl = new QLabel(args[i]);
                lbl->setFixedSize(40,20);
                lbl->setFont(f);
                QTextEdit* txt = new QTextEdit();
                txt->setFixedSize(40,20);
                txt->setFontPointSize(6);
                layout->addWidget(lbl,i+1,1,1,1);
                layout->addWidget(txt,i+1,2,1,1);
            }
            else {
                QTextEdit* txt = new QTextEdit();
                txt->setFixedSize(40,20);
                txt->setFontPointSize(6);
                layout->addWidget(txt,i+1,1);
            }
        }
    }
}

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
        if(!this->hiddingSomething){
            myMenu.addAction("Hide");}
        if(this->hiddingSomething){
            myMenu.addAction("Show");}
        QAction *selectedItem=myMenu.exec(globalPos);

        if(selectedItem){
            if(selectedItem->toolTip()=="Delete"){
                qDebug()<<"Delete";
                this->close();
                this->exist=false;
                //this->p->removeNode(this);
            }
            else if(selectedItem->toolTip()=="Hide"){
                qDebug()<< "Hide";
                if(!this->parentNodes.empty()){
                    this->hiddingSomething=true;
                    Node *node=this;
                    std::stack<Node *> stek;
                    bool begining=true;
                    while(!node->parentNodes.empty() || !stek.empty() || begining==true){
                        begining=false;
                        int childNum=node->parentNodes.size();
                        int i=0;
                        for(; i<childNum; i++){

                            if(node->parentNodes[i]->getVisitedHide()==false){
                                node->parentNodes[i]->setVisitedHide(true);
                                node->parentNodes[i]->isHidden=true;
                                node->parentNodes[i]->hide();
                                stek.push(node->parentNodes[i]);
                            }
                        }
                        node=stek.top();
                        stek.pop();
                        node->setVisitedHide(false);
                        node->hide();
                    }
                    QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
                    bodyShadow->setBlurRadius(13.0);
                    //QColor color=this->palette().color(backgroundRole());
                    bodyShadow->setColor(this->palette().Dark);
                    bodyShadow->setOffset(8.0);
                    this->setGraphicsEffect(bodyShadow);

                }
            } else if(selectedItem->toolTip()=="Show"){
                qDebug()<< "Show";
                if(!this->parentNodes.empty()){
                    this->hiddingSomething=false;
                    Node *node=this;
                    std::stack<Node *> stek;
                    bool begining=true;
                    while(!node->parentNodes.empty() || !stek.empty() || begining==true){
                        begining=false;
                        int childNum=node->parentNodes.size();
                        int i=0;
                        for(; i<childNum; i++){

                            if(node->parentNodes[i]->getVisitedHide()==false){
                                node->parentNodes[i]->setVisitedHide(true);
                                node->parentNodes[i]->isHidden=false;
                                node->parentNodes[i]->show();

                                stek.push(node->parentNodes[i]);
                            }
                        }
                        node=stek.top();
                        stek.pop();
                        node->setVisitedHide(false);
                        node->show();
                    }
                    this->setGraphicsEffect(nullptr);
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
    QFrame::mousePressEvent(event);
}

void Node::applyColors(){
    int i;
    for (i = 0;i<inputs.size();i++)
        inputs[i]->setStyleSheet(colors[inputTypes[i]]);
    for (i=0;i<outputs.size();i++)
        outputs[i]->setStyleSheet(colors[outputTypes[i]]);
}

void Node::setColors(QVector<QChar> v){
    int i=0;
    for(;i<inputs.size();i++){
        inputTypes.push_back(v[i]);
        inputs[i]->setColor(v[i]);
    }
    int n = i;
    for(i=0;i<outputs.size();i++){
        outputTypes.push_back(v[n+i]);
        outputs[i]->setColor(v[n+i]);
    }
    applyColors();
}

QMap<QChar,QString> Node::getColors(){
    return colors;
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

QVector<Node*>& Node::getChildren()
{
    return this->childNodes;
}

QVector<Node *>& Node::getParents()
{
    return this->parentNodes;
}

QPoint* Node::getOldPos(){
    return &oldPos_;
}

QVector<Input*>* Node::getInputs(){
    return &(this->inputs);
}
QVector<Output*>* Node::getOutputs(){
    return &(this->outputs);
}

QString Node::getCodeForNode(){
    return "";
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

QVector<Node *> Node::getParentNodes()
{
    return parentNodes;
}


