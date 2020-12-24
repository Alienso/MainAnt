#ifndef MAPNODE_H
#define MAPNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QLabel>

#include "./headers/Node.h"

class MapNode :public Node
{
public:
    MapNode();

    QLineEdit* mapName;
    QComboBox* keyTypes;
    QComboBox* valueTypes;

    QString getCodeForNode() override;

};

#endif // MAPNODE_H
