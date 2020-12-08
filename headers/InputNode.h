#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H

#include <QTextEdit>
#include <QFont>
#include <QString>
#include <QLineEdit>
#include <QApplication>
#include <QClipboard>
#include <QFormLayout>
#include <iostream>
#include "./headers/Node.h"

class InputNode : public Node
{
private:
    QString text = nullptr;
    QLineEdit* input;

public:
    InputNode();
    QString getCodeForNode() override;
    QString getText() const;
};

#endif // OUTPUTNODE_H
