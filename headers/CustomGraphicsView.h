#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGridLayout>

#include <./headers/Node.h>
#include <./headers/Input.h>

class CustomGraphicsView : public QGraphicsView{
private:
    QVector<Node*>* nodes;

public:
    explicit CustomGraphicsView (QWidget *parent = nullptr);
    void addWidget(Node* w);

    QVector<Node*>* getNodes();

protected:
    void paintEvent(QPaintEvent*);
    void repositionNodes();
};

#endif // CUSTOMGRAPHICSVIEW_H
