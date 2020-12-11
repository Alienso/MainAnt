#include "./headers/CustomGraphicsView.h"

CustomGraphicsView::CustomGraphicsView(QWidget* parent)
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

    //QPen pen(Qt::red);
    //pen.setWidth(8);

    painter.setPen(QPen(QBrush(grad1),7));
    repositionNodes();

    //Povezivanje Node-ova TODO
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
    update();
}
//Vraca nodeove nazad na svoje mesto nakon dodavanja novog node-a
//TODO
void CustomGraphicsView::repositionNodes()
{

    for (Node* n : *nodes){
        if (n->pos() != *(n->getOldPos()))
            n->move(n->getOldPos()->x(),n->getOldPos()->y());
    }
}

QVector<Node*>* CustomGraphicsView::getNodes()
{
    return nodes;
}
