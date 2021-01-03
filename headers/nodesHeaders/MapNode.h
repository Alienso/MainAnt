#ifndef MAPNODE_H
#define MAPNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QPushButton>


#include "./headers/Node.h"

class MapNode :public Node
{
    Q_OBJECT
public:
    MapNode();

    QLineEdit* mapName;
    QComboBox* keyTypes;
    QComboBox* valueTypes;

    QVector<QString> initializedVars;
    QVector<QString> initializedKeys;

    QLineEdit* inKey;
    QLineEdit* inValue;
    QLineEdit* lastTwo;
    QPushButton* addVar;
    QPushButton* removeVar;
    QString lasTwoText = "empty map";
    QButtonGroup *choice;
    QRadioButton* initialize;
    QRadioButton* notInitialize;

    int initialSize = 260;

    QString getCodeForNode() override;
    QString getVarName() const override;
    void genererateLastTwoText();

public slots:
    void addVariable();
    void removeVariable();

};

#endif // MAPNODE_H
