#ifndef NODE_H
#define NODE_H

#include <QFrame>
#include <QMouseEvent>
#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include "./headers/Output.h"
#include <./headers/Input.h>
#include <iostream>


class Node : public QFrame{
     Q_OBJECT
public:
    explicit Node(QWidget* parent=nullptr);
    Node(QWidget* parent,int ninputs);
    void addWidget(QWidget* w);
protected:
    //void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QPoint offset;
};

#endif // NODE_H
