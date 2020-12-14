#ifndef PRINTNODE_H
#define PRINTNODE_H

#include <QString>
#include <QTextEdit>
#include <QFont>
#include <QFormLayout>
#include <QTextEdit>
#include <QAbstractButton>
#include <QRadioButton>
#include <QButtonGroup>
#include "./headers/Node.h"

class PrintNode : public Node
{
private:
    bool manualInput;
    bool fileInput;
    bool printMyInput;
    QTextEdit* input;

public:
    PrintNode();
    QString getCodeForNode() override;
};

#endif // PRINTNODE_H
