#ifndef METHODNODE_H
#define METHODNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>

#include "./headers/Node.h"

class MethodNode : public Node
{
    Q_OBJECT
public:
    MethodNode();
    QLineEdit* MethodName;
    QComboBox* comboMethod;
    QComboBox* combo;
    QPushButton *addArg;
    QVector<QPushButton*> deleteButton;
    QVector<QLineEdit*> argumentsNames;
    QVector<QComboBox*> argumentsTypes;
    //do kog koeficijenta smo stigli u layoutu sa dodavanjem
    int layoutK=5;
    QString getCodeForNode() override;

public slots:
    void addArgument();
    void deleteArgument();
};

#endif // METHODNODE_H
