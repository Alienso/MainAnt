#ifndef VECTORNODE_H
#define VECTORNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QPushButton>

#include "./headers/Node.h"

class VectorNode : public Node
{
      Q_OBJECT
public:
    VectorNode();

    QLineEdit* vectorName;
    QLineEdit* capacity;
    QComboBox* varTypes;
    QVector<QString> initializedVars;

    QLineEdit* in;
    QLineEdit* lastFive;
    QPushButton* addVar;
    QPushButton* removeVar;
    QString lasFiveText = "empty vector";
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

#endif // VECTORNODE_H
