#ifndef VARNODE_H
#define VARNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>

#include "./headers/Node.h"


class VarNode : public Node
{
public:
    VarNode();
    QLineEdit* value;
    QLineEdit* varName;
    QComboBox* combo;
    QListWidgetItem* listItem;

    QString getCodeForNode() override;
    QString getVarName() const override;
    QLineEdit* getVarName();
    QListWidgetItem* getListItem();

};

#endif // VARNODE_H
