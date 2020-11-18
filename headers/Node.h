#ifndef NODE_H
#define NODE_H

#include <QFrame>
#include <QVector>
#include <QMouseEvent>
#include <QWidget>
#include <QLayout>
#include <QFormLayout>

#include <iostream>

#include "./headers/Output.h"
#include <./headers/Input.h>


class Node : public QFrame{
     Q_OBJECT
public:
    explicit Node(QWidget* parent=nullptr);
    Node(QWidget* parent,int ninputs);
    Node(QWidget* parent,int ninputs,int noutputs);
    Node(QString name,QWidget* parent,int ninputs,int noutputs);
    void addWidget(QWidget* w);
protected:
    //void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QPoint offset;
    QVector<Input*> inputs;
    Output* output;
    Node* next;
};

#endif // NODE_H
