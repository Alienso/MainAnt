#ifndef OUTPUT_H
#define OUTPUT_H

#include <QListWidget>
#include <QMouseEvent>
#include <QString>
#include <iostream>

class Output : public QListWidget
{
   public:
      explicit Output (QWidget *parent = nullptr);

   protected:
      void startDrag(Qt::DropActions supportedActions) override;
    private:
      QString addrtos(QWidget* w);
};

#endif // OUTPUT_H
