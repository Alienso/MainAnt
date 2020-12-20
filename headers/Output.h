#ifndef OUTPUT_H
#define OUTPUT_H

#include <QListWidget>
#include <QMouseEvent>
#include <QString>
#include <iostream>
#include <QMimeData>
#include <QDrag>
#include <sstream>

#include "./headers/Node.h"
#include "./CustomGraphicsView.h"

class CustomGraphicsView;
class Input;

class Output : public QListWidget
{
private:
    Input* next;
    QPoint offset;
    QChar color;
    QString addrtos(QWidget* w);

public:
    explicit Output (QWidget *parent = nullptr);
    QChar getColor();
    void setColor(QChar c);
    Input* getNext();
    void setNext(Input* ptr);

protected:
    void startDrag(Qt::DropActions supportedActions) override;
    //void mousePressEvent(QMouseEvent *event) override;
    //void mouseMoveEvent(QMouseEvent *event) override;
   // void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // OUTPUT_H
