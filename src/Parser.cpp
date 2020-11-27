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

QString  Parser::traverseGraph()
{
    std::cout<<"Pozvan"<<std::endl;
    Node* start = this->startNodes[0];
    //verovatno treba pop

    if (start == nullptr){
        std::cout<<"Nema vise start nodova"<<std::endl;
    }

    QMap<QString, Node*> nodes = this->getGraphScene();

    /*Node* returnNode = nodes["ReturnNode_node0"];
    if(returnNode == nullptr)
    {
        return QString::fromStdString("Fail");
    }

    QString code = returnNode->getCodeForNode();
    std::cout << code.toUtf8().constData() << std::endl;
    QVector<Input*>* inputs = returnNode->getInputs();


    Output* out = (*inputs)[0]->getPrevious();

    Node* parent = static_cast<Node*>(out->parent());

    std::cout << parent->getCodeForNode().toUtf8().constData();
    */
}
