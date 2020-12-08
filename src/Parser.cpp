#include "../headers/Parser.h"

bool Parser::checkType(std::string name, std::string expectedName)
{
    int cmp = name.compare(expectedName);
    if(cmp == 0){
        return true;
    }else{
        return false;
    }
}

Parser::Parser():id(0)
{
}

void Parser::addNode(Node* node, QString *type)
{
    std::string idString = std::to_string(this->id);
    std::string NodeType = type->toUtf8().constData();
    std::string tmp = NodeType + "_node" + idString;
    int len = tmp.size();

    node->setNodeId(QString::fromStdString(tmp));

    char charArray[len];
    strcpy(charArray, tmp.c_str());
    QString *name = new  QString(charArray);

    this->nodeNames.push_back(*name);
    this->graph.push_back(node);
    this->graphScene.insert(*name, node);
    this->id +=1;
}

void Parser::addNewStart(Node *node)
{
    this->startNodes.push_back(node);
}

QVector<QString> Parser::getNodeNames()
{
    return this->nodeNames;
}

QVector<Node *> Parser::getGraph()
{
    return this->graph;
}

QVector<Node *> Parser::getStartNodes()
{
    return this->startNodes;
}

QMap<QString, Node *> Parser::getGraphScene()
{
    return this->graphScene;
}

void Parser::removeNode(Node* node)
{
    auto it = this->graphScene.find(node->getNodeId());
    this->graphScene.erase(it);
}


QString  Parser::traverseGraph()//treba promeniti ime nije intuitivno
{
    file.open("../mainAntCode.cpp", std::ios::out|std::ios::trunc);
    if(this->startNodes.empty())
    {
        file<<"Nema startnih cvorova\n";
        return QString("");
    }else
    {
        file<<"#include <iostream>\n#include <string>\n";
        for(Node* startNode : this->startNodes){
            startNode->setVisited(true);
            file<<startNode->getCodeForNode().toUtf8().constData();
            QVector<Node*> children = startNode->getChildren();
            for(auto child : children){
                if(!child->getVisited()){
                    visitNode(child);
                }
            }

        }
    }
    file.close();
    return QString::fromStdString("Zavrsio sam");

}

void Parser::visitNode(Node* node)
{
    node->setVisited(true);
    QVector<Node*> parents = node->getParents();

    QString name = node->getName();
    std::string nodeName = name.toUtf8().constData();
    bool isIf = checkType(nodeName, "if");
    bool isWhile = checkType(nodeName, "while");
    bool isFor = checkType(nodeName, "for");

    if(isIf || isWhile || isFor){
        file<<nodeName<<"(";
    }



    if(!parents.empty())
    {
        for(Node* parent : parents){
            if(strcmp(parent->getName().toUtf8().constData(),("StartNode")) == 0)
            {
                continue;
            }
            else
            {
                if(!parent->getVisited()){
                    visitNode(parent);
                    if(isFor){
                        std::string parentName = parent->getName().toUtf8().constData();
                        bool isIncrement = checkType(parentName, "Increment");
                        if(!isIncrement){
                            file<<";";
                        }
                    }
                }
            }
        }
    }
    if(isIf || isWhile || isFor){
       file<<"){\n";
    }
    file<< node->getCodeForNode().toUtf8().constData();
    QVector<Node*> children = node->getChildren();
    if(children.empty()){
       return;
    }else{
       for(Node* child : children){
           if(!child->getVisited()){
              std::string childName = child->getName().toUtf8().constData();
              bool isBody = checkType(childName, "Body");
              visitNode(child);
              if(isBody){
                  file<<"\n}\n";
              }
           }
       }
    }
}
