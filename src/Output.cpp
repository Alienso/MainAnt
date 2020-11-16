#include "./headers/Output.h"
#include <QMimeData>
#include <QDrag>

Output::Output (QWidget *parent) : QListWidget(parent)
{
    setMinimumSize(20,20);
    setMaximumSize(20,20);
    setStyleSheet ("background-color: rgba(255, 0, 255, 1);");
    setDragEnabled(true);
}

void Output::startDrag(Qt::DropActions supportedActions)
{
   Q_UNUSED (supportedActions)

   auto mimeData = new QMimeData ();
   mimeData->setData("application/x-item", currentItem ()->text ().toUtf8 ());

   auto drag = new QDrag(this);
   drag->setMimeData (mimeData);
   drag->exec(Qt::MoveAction);
}
