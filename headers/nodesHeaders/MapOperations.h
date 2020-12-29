#ifndef MAPOPERATIONS_H
#define MAPOPERATIONS_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>

#include "./headers/Node.h"

class MapOperations : public Node
{
public:
    MapOperations();

    QLineEdit* value;
    QComboBox* operations;

    QString getCodeForNode() override;
};

#endif // MAPOPERATIONS_H
