#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGridLayout>
#include <./headers/Node.h>
#include <./headers/Input.h>

class CustomGraphicsView : public QGraphicsView{

public:
   explicit CustomGraphicsView (QWidget *parent = nullptr);
   QVector<Node*>* getNodes();
protected:
    void paintEvent(QPaintEvent*);
    void repositionNodes();
private:
    QVector<Node*>* nodes;
};

#endif // CUSTOMGRAPHICSVIEW_H
