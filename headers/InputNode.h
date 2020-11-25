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
    void resetInput();
private:
    QString* text = nullptr;
    QString* fileName = nullptr;
    bool manualInput;
    bool fileInput;
    QTextEdit* input;
};

#endif // OUTPUTNODE_H
