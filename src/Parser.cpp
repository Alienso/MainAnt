#include "../headers/Parser.h"

Parser::Parser():id(0)
{

}

void Parser::addNode(Node *node)
{
    std::string idString = std::to_string(this->id);
    std::string tmp = "node" + idString;
    int len = tmp.size();

    char charArray[len];
    strcpy(charArray, tmp.c_str());
    QString *name = new  QString(charArray);

    this->nodeNames.push_back(*name);
    this->graph.push_back(node);
    this->id +=1;

}

QVector<QString> Parser::getNodeNames()
{
    return this->nodeNames;
}
