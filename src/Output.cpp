#include "./headers/Output.h"
#include <QMimeData>
#include <QDrag>

Output::Output (QWidget *parent) : QListWidget(parent)
{
    setMinimumSize(20,20);
    setMaximumSize(20,20);
    setStyleSheet ("background-color: rgba(218, 129, 25, 1);");
    setDragEnabled(true);
}

void Output::startDrag(Qt::DropActions supportedActions)
{
   Q_UNUSED (supportedActions)

   auto mimeData = new QMimeData ();
   mimeData->setData("node_ptr", addrtos(this).toUtf8 ());

   auto drag = new QDrag(this);
   drag->setMimeData (mimeData);
   drag->exec(Qt::MoveAction);
}

//Address to String - addrtos
//Takes the address and returns a string of ones and zeroes
QString Output::addrtos(QWidget* w){
  uintptr_t x = (uintptr_t)w;
  unsigned size = sizeof(void*) * 8;
  unsigned mask;
  char addr[size+1];
  int i = 0;
  for (mask = 1 << (size - 1); mask != 0; mask >>= 1){
    addr[i]=(x & mask ? '1' : '0');
    i++;
  }
  addr[i] = '\0';
  return QString(addr);
}
