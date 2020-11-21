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

#include "./headers/Output.h"
#include "./headers/Input.h"

class Input;
class Output;


class Node : public QFrame{
     Q_OBJECT
public:
    explicit Node(QWidget* parent = nullptr);
    Node(QString name,int ninputs,int noutputs,QWidget* parent = nullptr);
    void addWidget(QWidget* w);
    QPoint* oldPos();
    QVector<Input*>* getInputs();
protected:
    //void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    QString name;
    QPoint offset;
    QPoint oldPos_;
    QVector<Input*> inputs;
    Output* output;
    Node* next;
    QLabel* nameLbl;
};

#endif // NODE_H
