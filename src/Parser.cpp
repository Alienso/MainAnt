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
    QString s = "";
    for(int i=0;i<getEndNodes().length();i++){
        if (getEndNodes()[i]->name.compare("if") == 0){
            s = "";
            QString res = traverse(getEndNodes()[i]->inputs[0]->getPrevious()); //Obidji ulaz if
            s.push_back(res);
            QString tmp = "if(" + traverse(getEndNodes()[i]->inputs[1]->getPrevious()) + "){" + ifMap[getEndNodes()[i]->getNodeId() + "_true"] + "}else{" + ifMap[getEndNodes()[i]->getNodeId() + "_false"] + "}" + ifMap[getEndNodes()[i]->getNodeId() + "_finaly"];
            s.push_back(tmp);
            continue;
        }
        QString res = traverse(getEndNodes()[i]->outputs[0]);
        if (fieldToWriteTo.compare(""))
            ifMap[fieldToWriteTo] = res;
        fieldToWriteTo = "";
        s.push_back(res);
    }
    return s;
}

/*QString Parser::traverse(Output* o){

    if (o == nullptr){
        return "Cao";
    }
    Node* curr = static_cast<Node*>(o->parentWidget());
    if (curr->visited)
        return "";
    curr->visited = true;

    QString s = curr->code;
    QString res = "";
    int i=0;
    for (Input* in: curr->inputs){
        QString rez = traverse(in->getPrevious());
        for (;i<s.length();i++){
            if (s[i] == '_'){
                res.append(rez);
                i++;
                break;
            }
            if (s[i] == "@"){
                res.append("#" + curr->nodeId + "#");
            }
            else res.append(s[i]);
        }
    }
    for (;i<s.length();i++){
        if (s[i] == "@"){
            res.append("#" + curr->nodeId + "#");
        }
        else res.append(s[i]);
    }
    return res;
}*/

QString Parser::traverse(Output* o){

    if (o == nullptr){
        return "";
    }
    Node* curr = static_cast<Node*>(o->parentWidget());

    QString s = curr->code;
    QString res = "";
    int i = 0;
    if (curr->hasFlowControl)
        i = 1;

    if (curr->name.compare("if") == 0){
        if (!curr->visited)
            endNodes.push_back(curr);
        curr->visited = true;
        if (o == curr->outputs[0]){
           fieldToWriteTo = curr->getNodeId() + "_finaly";
           return "";
        }
        if (o == curr->outputs[1]){
           fieldToWriteTo = curr->getNodeId() + "_true";
           return "";
         }
        if (o == curr->outputs[2]){
           fieldToWriteTo = curr->getNodeId() + "_false";
           return "";
         }
    }

    //MORA ovde zbog provere da li je if pre posecen

    if (curr->visited)
        return "";
    curr->visited = true;

    for (auto c : s){
        if (c == '_'){
            if ((curr->inputs[i]->getPrevious() == nullptr)){
                res.append("Cao");
                i++;
                continue;
            }
            QString rez = traverse(curr->inputs[i]->getPrevious());
            res.append(rez);
            i++;
            continue;
        }
        if (c == "@"){
            res.append("#" + curr->nodeId + "#");
        }
        else res.append(c);
    }
    if (curr->hasFlowControl){
        QString rez = traverse(curr->inputs[0]->getPrevious());
        res.append(rez);
    }
    return res;
}
