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
#include <QApplication>
#include <QClipboard>
#include <QFormLayout>
#include "./headers/Node.h"

class InputNode : public Node
{
private:
    QString* text = nullptr;
    QString* fileName = nullptr;
    bool manualInput;
    bool fileInput;
    QTextEdit* input;

public:
    InputNode();
    void resetInput();
    QString getCodeForNode() override;
    QString* getText();
};

#endif // OUTPUTNODE_H
