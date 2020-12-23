#ifndef PRASER_H
#define PRASER_H

#include <QVector>
#include <QString>
#include <QMap>
#include <string>
#include <string.h>
#include <iostream>
#include <cstring>
#include <fstream>

#include "./headers/Node.h"

class Node;

class Parser
{
private:
    //Pravate deo vezan za parsiranje korisnicki definisanih, funkcija
    QVector<Node*> functions;
    //Funkcija koja ispisuje definicije korisnicki definisanih funkcija u fajl koji se formira
    void writeMyFunctions(std::ofstream& formingFile, int funcNum);

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

    //stream za fal u koji cemo pisati kod
    std::ofstream file;
    //strema za fajl u koji pisemo kod korisnicki definisanih funkcija
    std::ofstream funcFile;

   //funkcija za proveru tipa noda
    bool checkType(std::string name, std::string expectedName);
    //Funkcija koja se pozoiva pre svakog obilasna grafa da resetuje flag visited za svaki cvor
    void resetVisted();

    //Funkcija koja otvara strim za pisanje i zapocinje obilazak grafa
    void traverseGraph(std::ofstream& out);
    //Funkcija koja obilazi cvorove scene i ispisuje dati kod u zadati strim
    void visitNode(Node* node, std::ofstream& out);

    //Funkcije za obilazak specijalnih nodova, kontrole toka ili slicno
    //POZIVAJU SE SAMO IZ VISITNODE metoda
    void visitForNode(Node* forNode, QVector<Node*> parents, QVector<Node*> children, std::ofstream& out);
    void visitWhileNode(Node* whileNode, QVector<Node*> parents, QVector<Node*> children, std::ofstream& out);
    void visitIfNode(Node* ifNode, QVector<Node*> parents, QVector<Node*> children, std::ofstream& out);
    void vistiBinaryNode(Node* node, QVector<Node*> parents, std::ofstream& out);
    void visitElseIfNode(Node* node, QVector<Node*> parents, std::ofstream& out);

public:
    explicit Parser();
    void addNode(Node* node, QString *type);
    void addNewStart(Node* node);
    void addNewFunction(Node* node);

    QVector<QString> getNodeNames();
    QVector<Node*> getGraph();
    //Ova funkcija je samo za tesstiranje NEMA smisla da neko ima pristup ovom vektoru
    QVector<Node*> getStartNodes();
    QMap<QString, Node*> getGraphScene();

    void removeNode(Node* node);

    //funkcija koja se poziva za akciju run
    QString compileAndRun(int funcNum);
    //funkcij akoja se zove z aakciju compile
    QString  compile(int funcNum);
    //poziva se kada se definise nova funkcija
    QString createFunctionCode(int funcNum);
    void createFunctionBlueprint(QVector<Node*>* nodes, int funcNum);

};

#endif // PRASER_H
