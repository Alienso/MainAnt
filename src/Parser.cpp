#include "../headers/Parser.h"

void Parser::writeMyFunctions(std::ofstream &formingFile, int funcNum)
{
    qDebug()<<"Pisem f-ju u fajl";
    int i = 0;
    for(; i < funcNum; i++){
        int num = i+1;
        std::string filePath = "Functions/function" + std::to_string(num) + ".cpp";
        //qDebug()<<QString::fromStdString(filePath);
        std::ifstream file (filePath);
        if(file.is_open()){
            std::string line;
            qDebug()<<"Citam funkcije iz function fajla";
            while(std::getline(file, line)){
                formingFile<<line<<"\n";
            }
            file.close();
        }else{
            qDebug()<<"Fajl se ne moze otvoriti";
        }
    }
}

void Parser::writeMyMethod(std::ofstream &formingFile, std::string filePath, QString className)
{
    std::ifstream file (filePath);
    if(file.is_open()){
        std::string line;
        int linesRead = 0;
        while(std::getline(file, line)){
            if(linesRead == 0){
                qDebug()<<line.c_str();
                QString readLine = "public " + QString::fromStdString(line);//dodali smo public samo da bi se poklopio poziv za createString
                qDebug()<<readLine;
                QStringList lista = readLine.split(" ");
                QString code = createQString(lista, true, className);

                formingFile<<code.toUtf8().constData()<<"\n";
                linesRead++;
                continue;

            }
            formingFile<<line<<"\n";
            linesRead++;
        }
        file.close();
    }else{
        qDebug()<<"Fajl se ne moze otvoriti";
    }
}

QString Parser::createQString(QStringList &collection, bool addClassName, QString className)
{
    //Mi saljemo vektor stringvoa koji na prvoj pozivciji ima modifikator prisstupa
    //Zelimo string bez modifikatora pristupa
    //Ako je addClassName true, onda znaci da na ime metoda dodamo ClassName::imemetoda

    QString code = "";
    int vectorSize = collection.size();
    code+=collection[1];
    //qDebug()<<collection;
    code+=" ";
    if(addClassName){
        code+=className;
        code+="::";
    }
    for(int i=2; i<vectorSize; i++){
        code+=collection[i];
        code+=" ";
    }
    qDebug()<<code.toUtf8().constData();
    return code;
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
    QString code = forNode->getCodeForNode();
    if(!parents.empty())
    {
        int i=0;
        for(Node* parent : parents){
            if(strcmp(parent->getName().toUtf8().constData(),("StartNode")) == 0)
            {
                continue;
            }
            else
            {
                if(!parent->getVisited()){
                    i++;
                    if (i!=2){
                        visitNode(parent, out);
                    }
                    else{
                        if (code.compare("")==0){
                            visitNode(parent,out);
                        }
                        else out<<code.toUtf8().constData();
                    }
                    std::string parentName = parent->getName().toUtf8().constData();
                    bool isIncrement = checkType(parentName, "Increment");
                    if(!isIncrement){
                        out<<";";
                    }
                 }
             }
         }
      }
    if(parents.size() == 1 && code.compare("") !=0){
        out<<";"<<code.toUtf8().constData()<<";";
    }
    out<<")\n";
    //Zelimo da obidjemo sve osim poslednjeg deteta cvora for, jer su oni sastavni deo ovog cvora, a poslednji je samo sledeca celina koda
    if(children.empty()){
       return;
    }else{

       int len = children.length();
       //ne zelimo da obidjemo poslednje dete
       len = len-1;
       //for(int i=0; i<len; i++){
           Node* child = static_cast<Node*>((*forNode->getOutputs())[0]->getNext()->parentWidget());
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
       //}
    }
}

void Parser::visitWhileNode(Node *whileNode, QVector<Node *> parents, QVector<Node *> children, std::ofstream& out)
{
    whileNode->setVisited(true);
    //Zelimo da obidjemo sve roditelje cvora while jer oni uticu na njegovo izracunavanje
    out<<"while"<<"(";
    QString code = whileNode->getCodeForNode();
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
    if (parents.size() == 1 && code.compare("") != 0){
        out<<code.toUtf8().constData();
    }
    out<<")\n";
    //Zelimo da obidjemo sve osim poslednjeg deteta cvora while, jer su oni sastavni deo ovog cvora, a poslednji je samo sledeca celina koda
    if(children.empty()){
       return;
    }else{

       int len = children.length();
       //ne zelimo da obidjemo poslednje dete
       len = len-1;
       //for(int i=0; i<len; i++){
           Node* child = static_cast<Node*>((*whileNode->getOutputs())[0]->getNext()->parentWidget());
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
       //}
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
    QString code = ifNode->getCodeForNode();
    if (parents.size()==1 && code.compare("")!=0){
        out<<code.toUtf8().constData();
    }
    out<<")\n";
    //Zelimo da obidjemo sve osim poslednjeg deteta cvora if, jer su oni sastavni deo ovog cvora, a poslednji je samo sledeca celina koda
    if(children.empty()){
       return;
    }else{

       int len = children.length();
       //ne zelimo da obidjemo poslednje dete
       len = len-1;
       //for(int i=0; i<len; i++){
           Node* child = static_cast<Node*>((*ifNode->getOutputs())[0]->getNext()->parentWidget());
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
      // }
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
    out<<"else ";
    visitIfNode(node,parents,node->getChildren(),out);
}

void Parser::visitFuncRefNode(Node *node, QVector<Node *> parents, std::ofstream &out)
{
    //ovaj cvor je zapravo poziv korisnicki definisane funkcije, treba samo roditelje da lepo obidjemo
    out<<node->getCodeForNode().toUtf8().constData();
    int n_args = node->getInputs()->size();
    int i=0;
    for(Node* parent : parents){
        if (i==0){
            i++;
            continue;
        }
        if(!parent->getVisited()){
            this->visitNode(parent,out);
        }
        i++;
        if (i!=n_args){
            out<< ", ";
        }
    }
    out<<");\n";
}

Parser::Parser():hasIO(false)
                ,hasVector(false)
                ,hasStack(false)
                ,hasMap(false)
                ,hasQueue(false)
                ,hasCstdio(false)
                ,id(0)
{
    headers = "";
}

void Parser::addNode(Node* node, QString *type)
{
    QString idString = QString::number(this->id);
    QString NodeType = type->toUtf8().constData();
    QString tmp = NodeType + "_node" + idString;

    node->setNodeId(tmp);

    this->nodeNames.push_back(tmp);
    this->graph.push_back(node);
    this->graphScene.insert(tmp, node);
    this->id +=1;
}

void Parser::addNewStart(Node *node)
{
    this->startNodes.push_back(node);
}

void Parser::removeStart(Node *node)
{
    int i=0;
    int j=-1;
    for(i=0; i<this->startNodes.size(); i++){
        if(this->startNodes[i]==node){
            j=i;
        }
    }
    this->startNodes.erase(this->startNodes.begin()+j);
}

void Parser::addNewFunction(Node *node)
{
    this->functions.push_back(node);
}

void Parser::addMethod(Node *node)
{
    this->methods.push_back(node);
}

void Parser::addNewClass(Node *node)
{
    this->classes.push_back(node);
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

void Parser::eraseStartNode(QString name)
{
    int pos = -1;
    int i =0;
    for(auto node : startNodes){
        QString n = node->getName();
        int cmp = n.compare(name);
        //Ako su sjednaki stringovi pamtimo poziciju od pocetka
        if(cmp == 0){
            pos = i;
            //Mozemo da prekinemo jer znamo da su sva imena cvorova jedinstvena i da se svaki
            //startni cvor moze smao jednom dodari u vektor startnih cvorova
            break;
        }
        i++;
    }
    startNodes.erase(startNodes.begin() + pos);
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

#ifdef Q_OS_UNIX
    system("g++ -o mainAnt ../mainAntCode.cpp");
    system("./mainAnt");
#endif
#ifdef Q_OS_WIN
    system("g++ -o mainAnt.exe ../mainAntCode.cpp");
    system("mainAnt.exe");
#endif


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
    bool isFuncRef = node->funcRef;

    /*size_t isBinary = nodeName.find("_");
    if(isBinary == 6){
        this->vistiBinaryNode(node, parents, out);
    }*/

    if(isFor){
        this->visitForNode(node, parents, children, out);
    }else if(isWhile){
        this->visitWhileNode(node, parents, children, out);
    }else if(isIf){
        this->visitIfNode(node, parents, children, out);
    }else if(isElseIf){
        this->visitElseIfNode(node, parents, out);
    }else if(isFuncRef){
        this->visitFuncRefNode(node, parents, out);
    }

    node->setVisited(true);

    if(!isIf && !isElseIf && !isReferenc && !isFuncRef && !isWhile && !isFor){
        QString code = node->getCodeForNode();
        for(int i = 0;i<code.length();i++){
            QChar c = code[i];
            if(c == "#"){
                i++;
                int n_arg = code[i].toLatin1() - 48;
                if ((*(node->getInputs()))[n_arg]->getPrevious() != nullptr){
                    Node* parent = static_cast<Node*>(((*(node->getInputs()))[n_arg]->getPrevious()->parentWidget()));
                    if(strcmp(parent->getName().toUtf8().constData(),("StartNode")) == 0)
                    {
                        continue;
                    }
                    else
                    {
                        if(!parent->getVisited()){
                            visitNode(parent,out);
                        }
                    }
                }
            }
            else out<<c.toLatin1();
        }
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
#ifdef Q_OS_UNIX
        system("rm -r Functions");
#endif
#ifdef Q_OS_WIN
        system("rd /s /q Functions");
#endif
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
            funcFile<<"{\n";

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
    qDebug()<<"Creating method";
    if(methodNum == 1){
        //Ova komanda ne uspeva samo prvi put kad ovaj direktrijum ne postoji

#ifdef Q_OS_UNIX
        std::string comand_ = "rm -r Class" + std::to_string(classNum);
        const char* comand = comand_.c_str();
        qDebug()<<QString::fromStdString(comand_);
        system(comand);
#endif
#ifdef Q_OS_WIN
        std::string comand_ = "rd /s /q Class" + std::to_string(classNum);
        const char* comand = comand_.c_str();
        system(comand);
#endif
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
            QString methodCode = method->getCodeForNode();
            methodCode = methodCode.trimmed();
            QStringList stringArray = methodCode.split(" ");
            QString code = createQString(stringArray, false, "");
            methodFile<<code.toUtf8().constData();
            methodFile<<"{\n";

            QVector<Node*> children = method->getChildren();
            for(auto child : children){
                visitNode(child, this->methodFile);
            }
        }
    }

    this->methodFile.close();
    return "metod isparsiran";
}

QString Parser:: crateClassCode(QString className, int classId, int methodNum,
                               QVector<QString> publicMethods, QVector<QString> privateMethods, QVector<QString> protectedMethods,
                               QVector<Node*> publicAttributes, QVector<Node*> privateAttributes, QVector<Node*> protectedAttributes)
{
    //Pravimoo header clase
    QString comand = "../" + className + ".hpp";
    std::string headerFilePath = comand.toUtf8().constData();
    headerClass.open(headerFilePath, std::ios::out | std::ios::trunc);
    headerClass<<"#ifndef __";
    QString classNameUpper = className.toUpper();
    headerClass<< classNameUpper.toUtf8().constData();
    headerClass<< "_H__\n";
    headerClass<<"#define __ ";
    headerClass<< classNameUpper.toUtf8().constData();
    headerClass<<"_H__\n";

    Node* classNode = classes[0];
    headerClass<<classNode->getCodeForNode().toUtf8().constData();

    //pisemo deklaracije metoda u fajl
    if(privateMethods.size() != 0){
        headerClass<<"private:\n";
        for(auto method : privateMethods){
            method = method.trimmed();
            QStringList stringArray = method.split(" ");
            QString code = createQString(stringArray, false, "");
            headerClass<<"\t"<<code.toUtf8().constData()<<";\n";
        }
    }
    if(protectedMethods.size() != 0){
        headerClass<<"protected:\n";
        for(auto method : protectedMethods){
            method = method.trimmed();
            QStringList stringArray = method.split(" ");
            QString code = createQString(stringArray, false, "");
            headerClass<<"\t"<<code.toUtf8().constData()<<";\n";
        }
    }
    if(publicMethods.size() != 0){
        headerClass<<"public:\n";
        for(auto method : publicMethods){
            method = method.trimmed();
            QStringList stringArray = method.split(" ");
            QString code = createQString(stringArray, false, "");
            headerClass<<"\t"<<code.toUtf8().constData()<<";\n";
        }
    }
    //definisemo polja klase
    if(privateAttributes.size() != 0){
        headerClass<<"private:\n";
        for(auto atr : privateAttributes){
            headerClass<<"\t"<<atr->getCodeForNode().toUtf8().constData()<<";\n";
        }
    }
    if(protectedAttributes.size() != 0){
        headerClass<<"protected:\n";
        for(auto atr : protectedAttributes){
            headerClass<<"\t"<<atr->getCodeForNode().toUtf8().constData()<<";\n";
        }
    }
    if(publicAttributes.size() != 0){
        headerClass<<"public:\n";
        for(auto atr : publicAttributes){
            headerClass<<"\t"<<atr->getCodeForNode().toUtf8().constData()<<";\n";
        }
    }

    headerClass<<"};\n#endif\n";
    headerClass.close();

    //pravimo cpp fajl klase
    QString hppFile = className  + ".hpp"; //koristicemo za includ d a znamo sta da includujemo
    QString comand1 = "../" + className + ".cpp";
    std::string cppFilePath = comand1.toUtf8().constData();
    cppClass.open(cppFilePath, std::ios::out | std::ios::trunc);
    cppClass<<"#include \""<<hppFile.toUtf8().constData()<<"\""<<"\n";

    //Sve funkcije koje su deklarisane u okviru ove klase nalaze se u ovom direktorijumu
    QString rootdirq = "Class" + QString::fromStdString(std::to_string(classId));
    std::string rootdir = rootdirq.toUtf8().constData();
    //Sada prolazimo kroz cppp fajlove yu kojima su deklaracije funkcija i sve ih prepisujemo jednu ispod druge u zajednici cpp fajl
    for(int i=0; i<methodNum; i++){
        int num = i+1;
        std::string filePath =  rootdir + "/method" + std::to_string(num) + ".cpp";
        system("pwd");
        qDebug()<<filePath.c_str();
        writeMyMethod(cppClass, filePath, className);

    }

    cppClass.close();
    this->setHeader(hppFile.toUtf8().constData());

    return "klasa isparsirana";
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
    cmp = header.compare("cstdio");
    if(cmp == 0){
        if (hasCstdio == false){
            hasCstdio = true;
            this->headers += "#include <cstdio>\n";
        }
        return;
    }

    //Ako ni nije ni jedan od ovih headera onda znamo da je f-Ja pozvana da bi se dodao header za korisnicki definisanu klasu
    this->headers+="#includ \"";
    this->headers+=header;
    this->headers+="\"\n";
}
