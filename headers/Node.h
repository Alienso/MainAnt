#ifndef NODE_H
#define NODE_H

#include <QFrame>
#include <QVector>
#include <QMouseEvent>
#include <QWidget>
#include <QLayout>
#include <QFormLayout>

#include <iostream>

#include "Output.h"
#include "Input.h"

class Input;
class Output;


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
    QString name;
    QPoint offset;
    QVector<Input*> inputs;
    Output* output;
    Node* next;
    QLabel* nameLbl;
};

#endif // NODE_H
