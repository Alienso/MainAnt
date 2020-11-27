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
#include <QMenu>

class Input;
class Output;


class Node : public QFrame{
    Q_OBJECT
private:
    QString name;
    QPoint offset;
    QPoint oldPos_;
    QVector<Input*> inputs;
    Output* output;
    Node* next;
    QLabel* nameLbl;
    QString formatText;
    QString nodeId;

public:
    explicit Node(QWidget* parent = nullptr);
    Node(QString name,int ninputs,int noutputs,QWidget* parent = nullptr);
    void addWidget(QWidget* w);

    void setNodeId(QString nodeId);

    QPoint* getOldPos();
    QVector<Input*>* getInputs();
    virtual QString getCodeForNode();
    QString getNodeId();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // NODE_H
