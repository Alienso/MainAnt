#ifndef PRASER_H
#define PRASER_H

#include <QVector>
#include <QString>
#include <QMap>
#include <string>
#include "./headers/Node.h"

class Parser
{
public:
    explicit Parser();
    void addNode(Node* node, QString *type);

    QVector<QString> getNodeNames();
    QVector<Node*> getGraph();
    QMap<QString, Node*> getGraphScene();
    void removeNode(Node* node, QString* type);

private:
    //Vekror koji cuva cvorove grafa scene
    QVector<Node*> graph;

    //Vektor koji cuva imena svih cvorova grafa scene i prati red dodavanja u gornji vektor
    QVector<QString> nodeNames;

    //Zelimo mapa prvi el je ime cvora drugi pokazivac na cvor
    QMap<QString, Node*> graphScene;

    //Promenljiva se koristi kao id cvora u listi, i sluzi pri formiranju imena cvorova scene
    //radi lakseg pristupanja metodama klase datog cvora i slicno
    int id;

};

#endif // PRASER_H
