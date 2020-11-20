#ifndef NODE_H
#define NODE_H

#include <QFrame>
#include <QVector>
#include <QMouseEvent>
#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include <QDebug>

#include <iostream>

#include "Output.h"
#include "Input.h"

class Input;
class Output;


class Node : public QFrame{
     Q_OBJECT
public:
    explicit Node(QWidget* parent = nullptr);
    Node(QString name,int ninputs,int noutputs,QWidget* parent = nullptr);
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
