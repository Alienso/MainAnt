#include "./headers/Input.h"
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QLayout>
#include <QMimeData>
#include <QLabel>

Input::Input (QWidget *parent) : QFrame (parent)
{
   setMinimumSize(20,20);
   setMaximumSize(20,20);
   setAcceptDrops(true);
   setStyleSheet ("background-color: rgba(255, 0, 0, 1);");
}

void Input::dropEvent(QDropEvent *event)
{
   auto t = event->mimeData()->data("application/x-item");

   if (!t.isEmpty ())
   {
      auto label = new QLabel (t);
      label->setStyleSheet ("border: 1px solid black; background-color: white; qproperty-alignment: AlignCenter");
      layout ()->addWidget(label);

      setStyleSheet ("background-color: rgba(255, 0, 0, 1);");
   }

   event->accept ();
}

void Input::dragEnterEvent(QDragEnterEvent *event)
{
   event->accept ();

   setStyleSheet ("background-color: rgba(255, 0, 0, 0.5);");
}

void Input::dragLeaveEvent(QDragLeaveEvent *event)
{
   event->accept ();

   setStyleSheet ("background-color: rgba(255, 0, 0, 1);");
}
