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

void Parser::resetVisted()
{
    auto scene = this->getGraphScene();
    for(auto node : scene){
        node->setVisited(false);
    }
}

void Parser::visitForNode(Node *forNode, QVector<Node*> parents, QVector<Node*> children, std::ofstream& out)
{
    forNode->setVisited(true);
    //Zelimo da obidjemo sve roditelje cvora For jer oni uticu na njegovo izracunavanje
    out<<"for"<<"(";
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
                    visitNode(parent, out);

                    std::string parentName = parent->getName().toUtf8().constData();
                    bool isIncrement = checkType(parentName, "Increment");
                    if(!isIncrement){
                        out<<";";
                    }
                 }
             }
         }
      }
    out<<")\n";
    //Zelimo da obidjemo sve osim poslednjeg deteta cvora for, jer su oni sastavni deo ovog cvora, a poslednji je samo sledeca celina koda
    if(children.empty()){
       return;
    }else{

       int len = children.length();
       //ne zelimo da obidjemo poslednje dete
       len = len-1;
       for(int i=0; i<len; i++){
           Node* child = children[i];
           if(!child->getVisited()){
              std::string childName = child->getName().toUtf8().constData();
              bool isBody = checkType(childName, "Body");
              if(isBody){
                  out<<"{";
              }
              visitNode(child, out);
              if(isBody){
                  out<<"\n}\n";
              }
           }
       }
    }
}

void Parser::visitWhileNode(Node *whileNode, QVector<Node *> parents, QVector<Node *> children, std::ofstream& out)
{
    whileNode->setVisited(true);
    //Zelimo da obidjemo sve roditelje cvora while jer oni uticu na njegovo izracunavanje
    out<<"while"<<"(";
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
                    visitNode(parent, out);
                }
             }
         }
      }
    out<<")\n";
    //Zelimo da obidjemo sve osim poslednjeg deteta cvora while, jer su oni sastavni deo ovog cvora, a poslednji je samo sledeca celina koda
    if(children.empty()){
       return;
    }else{

       int len = children.length();
       //ne zelimo da obidjemo poslednje dete
       len = len-1;
       for(int i=0; i<len; i++){
           Node* child = children[i];
           if(!child->getVisited()){
              std::string childName = child->getName().toUtf8().constData();
              bool isBody = checkType(childName, "Body");
              if(isBody){
                  out<<"{";
              }
              visitNode(child, out);
              if(isBody){
                  out<<"\n}\n";
              }
           }
       }
    }
}

void Parser::visitIfNode(Node *ifNode, QVector<Node *> parents, QVector<Node *> children, std::ofstream& out)
{
    ifNode->setVisited(true);
    //Zelimo da obidjemo sve roditelje cvora if jer oni uticu na njegovo izracunavanje
    out<<"if"<<"(";
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
                    visitNode(parent, out);
                }
             }
         }
      }
    out<<")\n";
    //Zelimo da obidjemo sve osim poslednjeg deteta cvora while, jer su oni sastavni deo ovog cvora, a poslednji je samo sledeca celina koda
    if(children.empty()){
       return;
    }else{

       int len = children.length();
       //ne zelimo da obidjemo poslednje dete
       len = len-1;
       for(int i=0; i<len; i++){
           Node* child = children[i];
           if(!child->getVisited()){
              std::string childName = child->getName().toUtf8().constData();
              bool isBody = checkType(childName, "Body");
              if(isBody){
                  out<<"{";
              }
              visitNode(child, out);
              if(isBody){
                  out<<"\n}\n";
              }
           }
       }
    }
}

void Parser::vistiBinaryNode(Node *node, QVector<Node *> parents, std::ofstream& out)
{
    //znamo da svaki Binary cvor ima dva roditelja pored, plus cvor koji je bio pre njega i vec je obidjen

   int i =0;
    for(Node* parent : parents){
        if(!parent->getVisited()){
            this->visitNode(parent, out);
            i++;
        }
        if(i == 1){
            out<<node->getCodeForNode().toUtf8().constData();
        }
    }
}

Parser::Parser():funcId(0),id(0)
{
}

void Parser::addNode(Node* node, QString *type)
{
    std::string idString = std::to_string(this->id);
    std::string NodeType = type->toUtf8().constData();
    std::string tmp = NodeType + "_node" + idString; //Promena duzine niske u sredini cini da program radi
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

void Parser::addNewFunction(Node *node)
{
    this->functions.push_back(node);
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

QString Parser::compileAndRun()
{
    file.open("../mainAntCode.cpp", std::ios::out|std::ios::trunc);
    this->traverseGraph(file);
    //system("g++ -o mainAnt../mainAntCode.cpp");
    //system("./mainAnt");
    file.close();

    return QString::fromStdString("Zavrsio sam");
}


void Parser::traverseGraph(std::ofstream& out){
    this->resetVisted();

    if(this->startNodes.empty())
    {
       out<<"Nema startnih cvorova\n";
    }else
    {
        out<<"#include <iostream>\n#include <string>\n";
        for(Node* startNode : this->startNodes){
            startNode->setVisited(true);
            out<<startNode->getCodeForNode().toUtf8().constData();
            QVector<Node*> children = startNode->getChildren();
            for(auto child : children){
                if(!child->getVisited()){
                    visitNode(child, out);
                }
            }

        }
    }

}

void Parser::visitNode(Node* node, std::ofstream& out)
{
    node->setVisited(true);
    QVector<Node*> parents = node->getParents();
    QVector<Node*> children = node->getChildren();

    QString name = node->getName();
    std::string nodeName = name.toUtf8().constData();
    bool isIf = checkType(nodeName, "if");
    bool isWhile = checkType(nodeName, "while");
    bool isFor = checkType(nodeName, "for");

    size_t isBinary = nodeName.find("_");
    if(isBinary == 6){
        this->vistiBinaryNode(node, parents, out);
    }

    if(isFor){
        this->visitForNode(node, parents, children, out);
    }else if(isWhile){
        this->visitWhileNode(node, parents, children, out);
    }else if(isIf){
        this->visitIfNode(node, parents, children, out);
    }

    node->setVisited(true);
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
                    visitNode(parent, out);

                }
            }
        }
    }
    if(isBinary != 6){
        out<< node->getCodeForNode().toUtf8().constData();
    }

    if(children.empty()){
       return;
    }else{
       for(Node* child : children){
           if(!child->getVisited()){
              std::string childName = child->getName().toUtf8().constData();
              bool isBody = checkType(childName, "Body");
              if(isBody){
                out<<"{\n";
              }
              visitNode(child, out);
              if(isBody){
                  out<<"\n}\n";
              }
           }
       }
    }
}

QString Parser::createFunction()
{
    //qDebug()<<"Called";
    this->funcId += 1;
    std::string fileName = "function" + std::to_string(this->funcId);
    std::string filePath = "../Functions/" + fileName + ".cpp";

    funcFile.open(filePath, std::ios::out|std::ios::trunc);

    for(Node* func : this->functions){
        if(!func->getVisited()){
            func->setVisited(true);
            funcFile<<func->getCodeForNode().toUtf8().constData();

            QVector<Node*> children = func->getChildren();
            for(auto child : children){
                visitNode(child, funcFile);
            }
        }
    }

    funcFile.close();
    return "Funkcija isparsirana";
}
