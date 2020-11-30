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
#include <QMenu>

#include "./headers/Output.h"
#include "./headers/Input.h"
#include "./headers/Parser.h"

class Input;
class Output;
class Parser;

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
public:
    Parser * p;

public:
    explicit Node(QWidget* parent = nullptr);
    Node(QString name,int ninputs,int noutputs,Parser *p_=nullptr, QWidget* parent = nullptr);
    void addWidget(QWidget* w);

    void setNodeId(QString nodeId);
    void addParents(Node* parent);
    void addChildren(Node* child);

    QPoint* getOldPos();
    QVector<Input*>* getInputs();
    virtual QString getCodeForNode();
    QString getNodeId();
    QString getName();
    QVector<Node *> getParentNodes();
    //TODO:Svaka klasa kkoaj nasledjuje node mora da implementira run metod. Run metod implemntira logiku cvora i poziva se od strane parsera
    //virtual void run() const = 0;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // NODE_H
