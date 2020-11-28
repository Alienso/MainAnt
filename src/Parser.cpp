#include "../headers/Parser.h"

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

void Parser::removeNode(Node* node, QString* type)
{
    auto it = this->graphScene.find(node->getNodeId());
    this->graphScene.erase(it);
}


QString  Parser::traverseGraph()//treba promeniti ime nije intuitivno
{
    qDebug()<<"Pozvan\n";
    if(this->startNodes.empty())
    {
        qDebug()<<"Nema startnih cvorova\n";
        return QString("");
    }else
    {
        for(Node* startNode : this->startNodes){
            startNode->setVisited(true);
            QVector<Node*> children = startNode->getChildren();
            for(auto child : children){
                if(!child->getVisited()){
                    visitNode(child);
                }
            }

        }
    }
    qDebug()<< "Kraj";
    return QString::fromStdString("Zavrsio sam");

}

void Parser::visitNode(Node* node)
{
    //qDebug()<<"Vist";
    node->setVisited(true);
   QVector<Node*> parents = node->getParents();
    if(!parents.empty())
    {
        //qDebug()<<"if roditelj";
        for(Node* parent : parents){
            if(strcmp(parent->getName().toUtf8().constData(),("StartNode")) == 0)
            {
                continue;
            }
            else
            {
                if(!parent->getVisited()){
                    visitNode(parent);
                }
            }
        }
    }
        //qDebug()<<"else";
        //node->run ovaj metod mora da ima svaki cvor da se izvrsi
        qDebug() << node->getCodeForNode();
        QVector<Node*> children = node->getChildren();
        if(children.empty()){
            return;
        }else{
            //qDebug()<<"Dete";
            for(Node* child : children)
                if(!child->getVisited())
                    visitNode(child);
        }

}
