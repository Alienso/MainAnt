#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGridLayout>

#include "./headers/Node.h"
#include "./headers/Input.h"

class Node;

class CustomGraphicsView : public QGraphicsView{
private:
    QVector<Node*>* nodes;
    QPoint mouseAt;
    QPoint startPos;
    QPoint offset;
    bool dragging = false;

public:
    explicit CustomGraphicsView (QWidget *parent = nullptr);
    void addWidget(Node* w);
    void setDragging(bool val);
    void setMouseAt(QPoint pos);
    void setStartPos(QPoint pos);

    QVector<Node*>* getNodes();

protected:
    void paintEvent(QPaintEvent*);
    void repositionNodes();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // CUSTOMGRAPHICSVIEW_H
