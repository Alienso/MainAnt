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

    this->endNodes.push_back(node);
    this->nodeNames.push_back(*name);
    this->graph.push_back(node);
    this->graphScene.insert(*name, node);
    this->id +=1;

    //std::cout<< "Dodat Node: " << node->name.toUtf8().constData() << "\n";
    //fflush(stdout);
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

QVector<Node*> Parser::getEndNodes(){
    return this->endNodes;
}

QMap<QString, Node *> Parser::getGraphScene()
{
    return this->graphScene;
}

void Parser::removeNode(Node* node)
{
    //auto it = this->graphScene.find(node->getNodeId());
    //this->graphScene.erase(it);
    int i=0;
    for (i=0;i<endNodes.length();i++)
        if (endNodes[i] == node){
            endNodes.remove(i);
            //std::cout << "Uklonjen Node: " << node->name.toUtf8().constData() << "\n";
            //fflush(stdout);
        }
    return;
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

QString Parser::traverse(Node* curr){

    if (curr->visited)
        return "";
    curr->visited = true;

    if (curr->name == "if"){
        /*if (this == ouput[0])
         *  s = "if(_){@}else{@}*"
         *if (this == output[1])
         *  s = "if(_){*}else{@}@"
         *else
         *  s = "if(_){@}else{*}@"
         * */
    }
    QString s = curr->code;
    QString res = "";
    int i=0;
    for (auto c : s){
        if (c == '_'){
            if ((curr->inputs[i]->getPrevious() == nullptr)){
                res.append("Cao");
                i++;
                continue;
            }
            QString rez = traverse(static_cast<Node*>(curr->inputs[i]->getPrevious()->parent()));
            res.append(rez);
            i++;
            continue;
        }
        if (c == "@"){
            res.append("#" + curr->nodeId + "#");
        }
        else res.append(c);
    }
    return res;
}
