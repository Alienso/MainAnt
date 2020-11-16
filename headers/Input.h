#ifndef INPUT_H
#define INPUT_H

#include <QFrame>

class QDropEvent;
class QDragEnterEvent;
class QDragLeaveEvent;

class Input : public QFrame
{
   public:
      explicit Input(QWidget *parent = nullptr);

   protected:
      void dropEvent(QDropEvent *event) override;
      void dragEnterEvent(QDragEnterEvent *event) override;
      void dragLeaveEvent (QDragLeaveEvent *event) override;
};

#endif // INPUT_H
