#include "./headers/Output.h"

Output::Output (QWidget *parent) : QListWidget(parent)
{
    setMinimumSize(20,20);
    setMaximumSize(20,20);
    setStyleSheet ("background-color: rgba(218, 129, 25, 1);");
    setDragEnabled(true);
    next = nullptr;
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

//Address to String - addrtos
//Takes the address and returns a string of ones and zeroes
QString Output::addrtos(QWidget* w){
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
