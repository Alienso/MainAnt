#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H
#include <QTextEdit>
#include <QFont>
#include <QString>
#include <QRadioButton>
#include <QButtonGroup>
#include <QPushButton>
#include <QAbstractButton>
#include <QLineEdit>
#include "./headers/Node.h"

class InputNode : public Node
{
public:
    InputNode();
private:
    QString* text = nullptr;
    QString* fileName = nullptr;
};

#endif // OUTPUTNODE_H
