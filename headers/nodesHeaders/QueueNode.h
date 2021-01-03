#ifndef QUEUENODE_H
#define QUEUENODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QPushButton>
#include <QVector>

#include "./headers/Node.h"

class QueueNode : public Node
{
    Q_OBJECT
public:
    QueueNode(QVector<QString>& _inicializedClases);

    QLineEdit* QueueName;
    QComboBox* varTypes;
    QLineEdit* capacity;
    QVector<QString> initializedVars;

    QLineEdit* in;
    QLineEdit* lastFive;
    QPushButton* addVar;
    QPushButton* removeVar;
    QString lastFiveText = "empty queue";
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

#endif // QUEUENODE_H
