#include "./headers/CustomGraphicsView.h"

CustomGraphicsView::CustomGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
    nodes = new QVector<Node*>();
    setRenderHint(QPainter::Antialiasing);
}

void CustomGraphicsView::addWidget(Node* w)
{
    this->layout()->addWidget(w);
    getNodes()->push_back(w);

}

void CustomGraphicsView::paintEvent(QPaintEvent* e)
{
    QPainter painter(viewport());
    QLinearGradient grad1(25,75,125,175);

    grad1.setStart(QPointF(0, 1));
    grad1.setFinalStop(QPointF(1, 0));
    grad1.setColorAt(0.0, QRgb(0xfbcd18));
    grad1.setColorAt(0.2, QRgb(0xeb7295));
    grad1.setColorAt(0.4, QRgb(0x7bd2e3));

    grad1.setColorAt(0.6, QRgb(0xfbcd18));
    grad1.setColorAt(0.8, QRgb(0xeb7295));
    grad1.setColorAt(1, QRgb(0x7bd2e3));
    grad1.setCoordinateMode(QGradient::StretchToDeviceMode);

    painter.setPen(QPen(QBrush(grad1),7));
    repositionNodes();

    QPoint a,b;
    for (Node* n : *nodes){
        for (Input* i : *(n->getInputs())){
            if (i->getPrevious() != nullptr && !qobject_cast<Node *>(i->getPrevious()->parentWidget())->isHidden && n->exist && qobject_cast<Node *>(i->getPrevious()->parentWidget())->exist){
                a = n->mapToParent(i->pos());
                b = (i->getPrevious()->parentWidget())->mapToParent(i->getPrevious()->pos());
                painter.drawLine(a,b);
            }
        }
    }
    if(this->dragging)
        painter.drawLine(this->startPos,this->mouseAt);
    update();
    QGraphicsView::paintEvent(e);
}
//Vraca nodeove nazad na svoje mesto nakon dodavanja novog node-a
void CustomGraphicsView::repositionNodes()
{

    for (Node* n : *nodes){
        if (n->pos() != *(n->getOldPos()))
            n->move(n->getOldPos()->x(),n->getOldPos()->y());
    }
}

QVector<Node*>* CustomGraphicsView::getNodes(){
    return nodes;
}
void CustomGraphicsView::setDragging(bool val){
    this->dragging = val;
}
void CustomGraphicsView::setMouseAt(QPoint pos){
    this->mouseAt = pos;
}
void CustomGraphicsView::setStartPos(QPoint pos){
    this->startPos = pos;
}

void CustomGraphicsView::mousePressEvent(QMouseEvent *event){
    setCursor(Qt::ClosedHandCursor);
    this->dragging = true;
    this->offset = event->pos();
    for (Node* n :*this->nodes){
        n->setOldPosCopy(*n->getOldPos());
    }
}
void CustomGraphicsView::mouseMoveEvent(QMouseEvent *event){
    if (this->dragging){
        for(Node* n:*this->nodes){
            n->move(mapToParent(*n->getOldPosCopy() + event->pos() - offset));
            n->setOldPos(*n->getOldPosCopy() + event->pos() - offset);
        }
    }
}
void CustomGraphicsView::mouseReleaseEvent(QMouseEvent *event){
    setCursor(Qt::ArrowCursor);
    this->dragging = false;
    for (Node* n :*this->nodes){
        n->setOldPosCopy(*n->getOldPos());
    }
}
