#ifndef OUTPUT_H
#define OUTPUT_H

#include <QListWidget>
#include <QMouseEvent>
#include <QString>
#include <iostream>
#include <QMimeData>
#include <QDrag>
#include <sstream>

#include "./headers/Node.h"

class Input;

class Output : public QListWidget
{
private:
    Input* next;
    QString addrtos(QWidget* w);

public:
    explicit Output (QWidget *parent = nullptr);

protected:
    void startDrag(Qt::DropActions supportedActions) override;
};

#endif // OUTPUT_H
