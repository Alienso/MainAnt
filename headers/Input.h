#ifndef INPUT_H
#define INPUT_H

#include <QFrame>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QLayout>
#include <QMimeData>
#include <QLabel>

#include <iostream>

#include "./headers/Output.h"

class Output;
class QDropEvent;
class QDragEnterEvent;
class QDragLeaveEvent;

class Input : public QFrame
{
   public:
      explicit Input(QWidget *parent = nullptr);
      Output* getPrevious();

   protected:
      void dropEvent(QDropEvent *event) override;
      void dragEnterEvent(QDragEnterEvent *event) override;
      void dragLeaveEvent (QDragLeaveEvent *event) override;

   private:
      Output* previous;
      uintptr_t stoaddr(std::string s);
};

#endif // INPUT_H
