#ifndef PRASER_H
#define PRASER_H

#include <QVector>
#include <QString>
#include <QMap>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>

#include "./headers/Node.h"

class Node;

class Parser
{
private:
    //Vekror koji cuva cvorove grafa scene
    QVector<Node*> graph;
    //Svaki put kad se doda start node on se doda i u ovaj graf
    QVector<Node*> startNodes;
    //Vektor koji cuva imena svih cvorova grafa scene i prati red dodavanja u gornji vektor
    QVector<QString> nodeNames;

    //Zelimo mapa prvi el je ime cvora drugi pokazivac na cvor
    QMap<QString, Node*> graphScene;

    //Promenljiva se koristi kao id cvora u listi, i sluzi pri formiranju imena cvorova scene
    //radi lakseg pristupanja metodama klase datog cvora i slicno
    int id;

    //stremi za fal u koji cemo pisati kod
    std::ofstream file;

   //funkcija za proveru tipa noda
    bool checkType(std::string name, std::string expectedName);
    //Funkcija koja se pozoiva pre svakog obilasna grafa da resetuje flag visited za svaki cvor
    void resetVisted();


public:
    explicit Parser();
    void addNode(Node* node, QString *type);
    void addNewStart(Node* node);

    QVector<QString> getNodeNames();
    QVector<Node*> getGraph();
    //Ova funkcija je samo za tesstiranje NEMA smisla da neko ima pristup ovom vektoru
    QVector<Node*> getStartNodes();
    QMap<QString, Node*> getGraphScene();

    void removeNode(Node* node);

    //Funkcija koja ce da obilazi graph i da generise kod
    QString traverseGraph();
    //Funkcija koja obilazi Nodove
    void visitNode(Node* node);
};

#endif // PRASER_H
