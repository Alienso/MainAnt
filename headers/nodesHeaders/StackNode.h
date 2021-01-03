#ifndef STACKNODE_H
#define STACKNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QPushButton>
#include <QVector>

#include "./headers/Node.h"

class StackNode : public Node
{
    Q_OBJECT
public:
    StackNode(QVector<QString> _inicializedClases);

    QLineEdit* StackName;
    QComboBox* varTypes;
    QLineEdit* capacity;
    QVector<QString> initializedVars;

    QLineEdit* in;
    QLineEdit* lastFive;
    QPushButton* addVar;
    QPushButton* removeVar;
    QString lastFiveText = "empty stack";
    QButtonGroup *choice;
    QRadioButton* initialize;
    QRadioButton* notInitialize;

    int initialSize = 220;

    QString getCodeForNode() override;
    QString getVarName() const override;
    void genererateLastFiveText();

public slots:
    void addVariable();
    void removeVariable();

};

#endif // STACKNODE_H
