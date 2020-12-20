#include "./headers/Output.h"

Output::Output (QWidget *parent) : QListWidget(parent)
{
    setMinimumSize(20,20);
    setMaximumSize(20,20);
    this->addItem("");
    setDragEnabled(true);
    next = nullptr;
}

//Address to String - addrtos
//Takes the address and returns a string of ones and zeroes
QString Output::addrtos(QWidget* w)
{
    //uintptr_t x = reinterpret_cast<uintptr_t>(w);
    const void * address = static_cast<const void*>(w);
    std::stringstream ss;
    ss << address;
    std::string name = ss.str();
    unsigned long x = std::stoul(name, nullptr, 0);
    unsigned size = sizeof(void*) * 8;
    unsigned long mask;
    char addr[size+1];
    int i = 0;
    for (mask = 1ul << (size - 1); mask != 0; mask >>= 1){
        addr[i]=(x & mask ? '1' : '0');
        i++;
    }
    addr[i] = '\0';
    return QString(addr);
}

void Output::startDrag(Qt::DropActions supportedActions)
{
    Q_UNUSED (supportedActions)

    auto mimeData = new QMimeData ();
    auto n = addrtos(this);
    mimeData->setData("node_ptr", n.toUtf8());


    auto drag = new QDrag(this);
    drag->setMimeData (mimeData);
    drag->exec(Qt::MoveAction);
}

void Output::setColor(QChar c){
    this->color = c;
}
QChar Output::getColor(){
    return this->color;
}
Input* Output::getNext(){
    return this->next;
}
void Output::setNext(Input* ptr){
    next = ptr;
}

/*void Output::mousePressEvent(QMouseEvent *event){
     offset = mapToParent(event->pos());
     if (childAt(event->pos())!=nullptr){
         static_cast<CustomGraphicsView*>(this->parentWidget()->parentWidget())->setDragging(true);
         static_cast<CustomGraphicsView*>(this->parentWidget()->parentWidget())->setStartPos(this->parentWidget()->mapToParent(event->pos()+offset));

     }
     QListWidget::mousePressEvent(event);
}*/

//Ovaj zabaguje povezivanje
/*void Output::mouseMoveEvent(QMouseEvent *event){
     static_cast<CustomGraphicsView*>(this->parentWidget()->parentWidget())->setMouseAt(this->parentWidget()->mapToParent(event->pos()+offset));
     QListWidget::mousePressEvent(event);
}*/

/*void Output::mouseReleaseEvent(QMouseEvent *event){
    static_cast<CustomGraphicsView*>(this->parentWidget()->parentWidget())->setDragging(false);
    QListWidget::mousePressEvent(event);
}*/
