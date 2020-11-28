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
    Node* next;//Ovo polje nam verovatno ne treba
    QLabel* nameLbl;
    QString formatText;
    QString nodeId;

    QVector<Node*> parentNodes;// inputi ovog cvora !!OVO MENJA SAMO! input klasa
    QVector<Node*> childNodes;// outputi ovog cvora !!OVO MENJA SAMO! input klasa
    bool visited;

public:
    explicit Node(QWidget* parent = nullptr);
    virtual QString getCodeForNode();
    Node(QString name,int ninputs,int noutputs,QWidget* parent = nullptr);
    void addWidget(QWidget* w);

    void setNodeId(QString nodeId);
    void addParents(Node* parent);
    void addChildren(Node* child);
    QVector<Node*> getChildren() const;
    QVector<Node*> getParents() const;

    QPoint* getOldPos();
    QVector<Input*>* getInputs();
    QString getNodeId();
    void setVisited(bool flag);
    bool getVisited();
    QString getName();
    //TODO:Svaka klasa kkoaj nasledjuje node mora da implementira run metod. Run metod implemntira logiku cvora i poziva se od strane parsera
    //virtual void run() const = 0;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // NODE_H
