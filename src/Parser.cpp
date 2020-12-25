#include "../headers/Parser.h"

void Parser::writeMyFunctions(std::ofstream &formingFile, int funcNum)
{
    qDebug()<<"Pisem f-ju u fajl";
    int i = 0;
    for(; i < funcNum; i++){
        int num = i+1;
        std::string filePath = "Functions/function" + std::to_string(num) + ".cpp";
        qDebug()<<QString::fromStdString(filePath);
        std::ifstream file (filePath);
        if(file.is_open()){
            std::string line;
            qDebug()<<"Citam kinije iz function fajla";
            while(std::getline(file, line)){
                formingFile<<line<<"\n";
            }
            file.close();
        }else{
            qDebug()<<"Fajl se ne moze otvoriti";
        }
    }
}

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

void Parser::visitElseIfNode(Node *node, QVector<Node *> parents, std::ofstream &out)
{
    //Zelimo samo na poseban nacin da obidjemo roditelje elseif cvora, tj samo uslov lepi da sklopimo
    out<<node->getCodeForNode().toUtf8().constData();
    for(Node* parent : parents){
        if(!parent->getVisited()){
            this->visitNode(parent, out);
        }
    }
    out<<")";

}

Parser::Parser():id(0)
                ,hasIO(false)
                ,hasVector(false)
                ,hasStack(false)
                ,hasMap(false)
                ,hasQueue(false)
{
    headers = "";
}

void Parser::addNode(Node* node, QString *type)
{
    std::string idString = std::to_string(this->id);
    std::string NodeType = type->toUtf8().constData();
    std::string tmp = NodeType + "_node" + idString; //Promena duzine niske u sredini cini da return radi ali zato ostali nmodeovi ne rade???
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

QString Parser::compileAndRun(int funcNum)
{
    file.open("../mainAntCode.cpp", std::ios::out|std::ios::trunc);
    file<<this->headers;
    this->writeMyFunctions(file, funcNum);
    this->traverseGraph(file);
    file.close();

    system("g++ -o mainAnt ../mainAntCode.cpp");
    system("./mainAnt");


    return QString::fromStdString("Zavrsio sam");
}

QString Parser::compile(int funcNum)
{
    file.open("../mainAntCode.cpp", std::ios::out|std::ios::trunc);
    file<<this->headers;
    this->writeMyFunctions(file, funcNum);
    this->traverseGraph(file);
    file.close();

    return QString::fromStdString("kompilirano");
}


void Parser::traverseGraph(std::ofstream& out){
    this->resetVisted();

    if(this->startNodes.empty())
    {
       out<<"Nema startnih cvorova\n";
    }else
    {
        //out<<"#include <iostream>\n#include <string>\n";
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
    bool isElseIf = checkType(nodeName, "elseIf");
    bool isReferenc = checkType(nodeName, "VariableRef");

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
    }else if(isElseIf){
        this->visitElseIfNode(node, parents, out);
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
    if(isBinary != 6 && !isElseIf && !isReferenc){
        out<< node->getCodeForNode().toUtf8().constData();
    }
    if(isReferenc){
        QString keyName = node->getCodeForNode();
        Node* referedNode = this->graphScene[keyName];
        out<<referedNode->getVarName().toUtf8().constData();
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

QString Parser::createFunctionCode(int funcNum)
{
    if(funcNum == 1){
        //Ova komanda ne uspeva samo prvi put kad aovaj direktrijum ne postoji
        system("rm -r Functions");
        system("mkdir Functions");
    }
    //Krairamo jedinstveno ime svakog fajla funkcije
    std::string fileName = "function" + std::to_string(funcNum);
    std::string filePath = "Functions/" + fileName + ".cpp";

    funcFile.open(filePath, std::ios::out|std::ios::trunc);

    //Na klasican nacin obilazimo cvorove na sceni
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

void Parser::createFunctionBlueprint(QVector<Node*>* nodes, int funcNum){
    std::string fileName = "function" + std::to_string(funcNum);
    std::string filePath = "../Functions/" + fileName + ".mant";

    funcFile.open(filePath, std::ios::out|std::ios::trunc);
    for (Node* n : *nodes)
        funcFile<<n->getNodeId().toUtf8().constData()<<" ";
    funcFile<<" "<<std::endl<<QString::number(nodes->size()).toUtf8().constData()<<std::endl;
    for (Node* n : *nodes){
        QString inputs = "";
        QString outputs = "";
        int k = 0;
        for (auto i: *n->getInputs()){
            if ((i!=nullptr) && (i->getPrevious()!=nullptr)){
                Node* to = static_cast<Node*>((i->getPrevious())->parentWidget());
                int no = -1;
                int j = 0;
                for (Output* o : *to->getOutputs()){
                    if (o == i->getPrevious())
                        no = j;
                    j++;
                }
                inputs.append(QString::number(k) + " " + to->getNodeId() + " " + QString::number(no) + " ");
                k++;
            }
            else k++;
        }
        k = 0;
        for (auto o: *n->getOutputs()){
            if ((o!=nullptr) && (o->getNext()!=nullptr)){
                Node* to = static_cast<Node*>((o->getNext())->parentWidget());
                int no = -1;
                int j = 0;
                for (Input* i:*to->getInputs()){
                    if (i == o->getNext())
                        no = j;
                    j++;
                }
                outputs.append(QString::number(k) + " " + to->getNodeId() + " " + QString::number(no) + " ");
                k++;
            }
        }

        funcFile<<n->getNodeId().toUtf8().constData()<<" "<<n->pos().x() <<" "<<n->pos().y()<<" ins "<<inputs.toUtf8().constData()<<" outs "<<outputs.toUtf8().constData()<<std::endl;
    }
    funcFile.close();
    return;
}

QString Parser::createMethodCode(int classNum, int methodNum)
{
    if(methodNum == 1){
        //Ova komanda ne uspeva samo prvi put kad aovaj direktrijum ne postoji
        std::string comand_ = "rm -r Class" + std::to_string(classNum);
        const char* comand = comand_.c_str();
        system(comand);
        std::string comand2_ = "mkdir Class" + std::to_string(classNum);
        const char* comand2 = comand2_.c_str();
        system(comand2);
    }
    //Krairamo jedinstveno ime svakog fajla funkcije
    std::string fileName = "method" + std::to_string(methodNum);
    std::string filePath = "Class"+ std::to_string(classNum) +"/" + fileName + ".cpp";

    this->methodFile.open(filePath, std::ios::out|std::ios::trunc);

    //Na klasican nacin obilazimo cvorove na sceni
    for(Node* method : this->methods){
        if(!method->getVisited()){
            method->setVisited(true);
            funcFile<<method->getCodeForNode().toUtf8().constData();

            QVector<Node*> children = method->getChildren();
            for(auto child : children){
                visitNode(child, this->methodFile);
            }
        }
    }

    this->methodFile.close();
    return "metod isparsirana";
}

void Parser::setHeader(std::string header)
{
    int cmp = header.compare("map");
    if(cmp == 0){
        if (hasMap == false){
            hasMap = true;
            this->headers += "#include <map>\n";
        }
        return;
    }
    cmp = header.compare("vector");
    if(cmp == 0){
        if (hasVector == false){
            hasVector = true;
            this->headers += "#include <vector>\n";
        }
        return;
    }
    cmp = header.compare("queue");
    if(cmp == 0){
        if (hasQueue == false){
            hasQueue = true;
            this->headers += "#include <queue>\n";
        }
        return;
    }
    cmp = header.compare("stack");
    if(cmp == 0){
        if (hasStack == false){
            hasStack = true;
            this->headers += "#include <stack>\n";
        }
        return;
    }
    cmp = header.compare("io");
    if(cmp == 0){
        if (hasIO == false){
            hasIO = true;
            this->headers += "#include <iostream>\n#include <string>\n";
        }
        return;
    }
}
