#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>

#include "./headers/Node.h"

class FunctionNode : public Node
{
    Q_OBJECT
public:
    FunctionNode();
    QLineEdit* FunctionName;
    QComboBox* combo;
    QPushButton *addArg;
    //argumenti
    //povratna vrednost
    QString getCodeForNode() override;

private slots:
    void addAgrument(void);
};


#endif // FUNCTIONNODE_H
