#ifndef NODE_H
#define NODE_H

#include <QFrame>
#include <QVector>
#include <QMouseEvent>
#include <QWidget>
#include <QLayout>
#include <QGridLayout>
#include <QDebug>
#include <iostream>
#include <QMenu>
#include <QTextEdit>
#include <bits/stdc++.h>
#include <QMenu>
#include <QGraphicsDropShadowEffect>

#include "./headers/Output.h"
#include "./headers/Input.h"
#include "./headers/Parser.h"

class Input;
class Output;
class Parser;

class Node : public QFrame{
    Q_OBJECT
protected:
    QString name;
    QPoint offset;
    QPoint oldPos_;
    QVector<Input*> inputs;
    QVector<Output*> outputs;
    QVector<QChar> inputTypes;
    QVector<QChar> outputTypes;
    QVector<QTextEdit*> args;
    QMap<QChar,QString> colors;
    Node* next;//Ovo polje nam verovatno ne treba
    QLabel* nameLbl;
    QString formatText;
    QString nodeId;
    QVector<Node*> parentNodes;// inputi ovog cvora !!OVO MENJA SAMO! input klasa
    QVector<Node*> childNodes;// outputi ovog cvora !!OVO MENJA SAMO! input klasa
    //flag za obilazak grafa
    bool visited;
    //ova dva flaga sluze za opcije show i hide
    bool  visitedHide=false;
    bool hiddingSomething=false;


protected:
    void applyColors();
public:
    Parser * p;
    bool exist=true;
    bool isHidden=false;
public:
    explicit Node(QWidget* parent = nullptr);
    Node(QString name,int ninputs,int noutputs,QVector<QString> args = {},Parser *p_=nullptr, QWidget* parent = nullptr);
    virtual QString getCodeForNode();
    
    void addWidget(QWidget* w);

    void setNodeId(QString nodeId);
    void setVisitedHide(bool);
    void addParents(Node* parent);
    void addChildren(Node* child);
    QVector<Node*>& getChildren();
    QVector<Node*>& getParents();

    QPoint* getOldPos();
    QVector<Input*>* getInputs();
    QVector<Output*>* getOutputs();
    QString getNodeId();
    void setVisited(bool flag);
    bool getVisited();
    bool getVisitedHide();
    QString getName();
    QVector<Node *> getParentNodes();
    void setColors(QVector<QChar> v);
    QMap<QChar,QString> getColors();

    //funkcija za referencirnaje
    virtual QString getVarName() const;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // NODE_H
