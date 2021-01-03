#include "./headers/Node.h"

Node::Node(QWidget *parent) : QFrame(parent)
{
    setMaximumSize(150,150);
    setStyleSheet ("background-color: rgba(24, 135, 127, 1);"
                   "border: 1px solid rgba(205, 221, 63, 1);"
                   "border-radius: 5px;"
                   );
    this->setLayout(new QGridLayout());
    *(this->getOldPos()) = this->pos();
    colors['i'] = "border-width: 2px;border-color: rgba(0, 194, 255, 1);border-radius: 10px;"; //int long
    colors['n'] = "border-width: 2px;border-color: rgba(173, 91, 219, 1);border-radius: 10px;"; //broj
    colors['f'] = "border-width: 2px;border-color: rgba(141, 233, 50, 1);border-radius: 10px;"; //float double
    colors['b'] = "border-width: 2px;border-color: rgba(255, 2, 116, 1);border-radius: 10px;"; //bool
    colors['s'] = "border-width: 2px;border-color: rgba(255, 156, 57, 1);border-radius: 10px;"; //string
    colors['c'] = "border-width: 2px;border-color: rgba(255, 104, 107, 1);border-radius: 10px;"; //char
    colors['q'] = "border-width: 2px;border-color: rgba(65, 247, 201, 1);border-top-right-radius: 10px;border-bottom-right-radius: 10px;"; //kontrola toka
    colors['v'] = "border-width: 2px;border-color: rgba(0, 0, 0, 1);border-radius: 10px;"; //int long
}

//TODO QT resetuje velicinu fonta u textEditu kada se sve izbrise
Node::Node(QString _name,int ninputs,int noutputs,QVector<QString> _args,QString code, QWidget* parent) : Node(parent)
{
    funcRef = false;
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->setHorizontalSpacing(2);
    layout->setVerticalSpacing(5);
    this->code = code;
    this->setMaximumSize(150, ninputs>noutputs ? 27*(ninputs+1) : 27*(noutputs+1));
    this->name = _name;
    this->nameLbl = new QLabel(name);
    if (_args.length() == 0){
        _args.resize(ninputs == 0 ? 1 : ninputs);
        for (int i=0;i<ninputs;i++)
            _args[i] = "";
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

        if (_args[i].compare("") != 0){
            QLabel* lbl = new QLabel(_args[i]);
            lbl->setFixedSize(40,20);
            lbl->setFont(f);
            QTextEdit* txt = new QTextEdit();
            txt->setFixedSize(40,20);
            txt->setFontPointSize(6);
            layout->addWidget(lbl,i+1,1,1,1);
            layout->addWidget(txt,i+1,2,1,1);
            this->args.push_back(txt);
        }
        else {
            QTextEdit* txt = new QTextEdit();
            txt->setFixedSize(40,20);
            txt->setFontPointSize(6);
            layout->addWidget(txt,i+1,1);
            this->args.push_back(txt);
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

            if (_args[i].compare("") != 0){
                QLabel* lbl = new QLabel(_args[i]);
                lbl->setFixedSize(40,20);
                lbl->setFont(f);
                QTextEdit* txt = new QTextEdit();
                txt->setFontPointSize(6);
                txt->setFixedSize(40,20);
                layout->addWidget(lbl,i+1,1,1,1);
                layout->addWidget(txt,i+1,2,1,1);
                this->args.push_back(txt);
            }
            else {
                QTextEdit* txt = new QTextEdit();
                txt->setFixedSize(40,20);
                txt->setFontPointSize(6);
                layout->addWidget(txt,i+1,1);
                this->args.push_back(txt);
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

            if (_args[i].compare("") != 0){
                QLabel* lbl = new QLabel(_args[i]);
                lbl->setFixedSize(40,20);
                lbl->setFont(f);
                QTextEdit* txt = new QTextEdit();
                txt->setFixedSize(40,20);
                txt->setFontPointSize(6);
                layout->addWidget(lbl,i+1,1,1,1);
                layout->addWidget(txt,i+1,2,1,1);
                this->args.push_back(txt);
            }
            else {
                QTextEdit* txt = new QTextEdit();
                txt->setFixedSize(40,20);
                txt->setFontPointSize(6);
                layout->addWidget(txt,i+1,1);
                this->args.push_back(txt);
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

void Node::deleteNodeInParentSlot(QString nodeId)
{
    int i=0;
    for(auto childrenOfNode : this->childNodes){
        if(childrenOfNode->nodeId==nodeId){
            this->childNodes.remove(i);
        }
        i++;
    }
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
                if(this->name=="Class" || this->name=="Method" || this->name=="Function" || this->name=="FunctionReturn"){
                    QMessageBox msgBox;
                    msgBox.setText("You can't delete " + this->name + "Node.");
                    msgBox.exec();
                }
                else{
                    //qDebug()<<"Delete";
                    this->close();
                    this->exist=false;
                    auto parentMainWindow=qobject_cast<QMainWindow*>(this->parent()->parent()->parent());
                    connect(this, SIGNAL(deletedReferencedNode(QString)), parentMainWindow, SLOT(onDeletedReferencedNode(QString)));
                    if(this->name=="var" || this->name=="vector" || this->name=="stack" || this->name=="queue" || this->name=="map"){
                        emit deletedReferencedNode(this->nodeId);
                    }
                    connect(this, SIGNAL(deletedStartNode(Node*)), parentMainWindow, SLOT(onDeletedStartNode(Node*)));
                    if(this->name=="StartNode"){
                        emit deletedStartNode(this);
                    }
                    this->destroy();
                }
                for(auto parentOfNode : this->parentNodes){
                    connect(this, SIGNAL(deleteNodeInParentSignal(QString)), parentOfNode, SLOT(deleteNodeInParentSlot(QString)));
                    emit(deleteNodeInParentSignal(this->nodeId));
                }
            }
            else if(selectedItem->toolTip()=="Hide"){
                //qDebug()<< "Hide";
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
                //qDebug()<< "Show";
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

QString Node::getVarName() const
{
    return "";
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
void Node::setOldPos(QPoint p){
    oldPos_ = p;
}

QPoint* Node::getOldPosCopy(){
    return &oldPosCopy;
}
void Node::setOldPosCopy(QPoint p){
    this->oldPosCopy = p;
}

QVector<Input*>* Node::getInputs(){
    return &(this->inputs);
}
QVector<Output*>* Node::getOutputs(){
    return &(this->outputs);
}

QString Node::getCodeForNode(){
    return code;
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


