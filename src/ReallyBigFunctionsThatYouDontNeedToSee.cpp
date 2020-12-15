#include "./headers/ReallyBigFunctionsThatYouDontNeedToSee.h"
#include "ui_mainwindow.h"

void functionsListInit(QMainWindow* m,QString s){

    MainWindow *w = static_cast<MainWindow*>(m);

    QListWidgetItem* plus = new QListWidgetItem(w->tr("+BinarySum"), w->getUi()->listWidget);
    QListWidgetItem* minus =new QListWidgetItem(w->tr("+BinaryMInus"),  w->getUi()->listWidget);
    QListWidgetItem* mul =new QListWidgetItem(w->tr("+BinaryMUltiply"),  w->getUi()->listWidget);
    QListWidgetItem* less =new QListWidgetItem(w->tr("+LessThan"),  w->getUi()->listWidget);
    QListWidgetItem* input =new QListWidgetItem(w->tr("+Input"),  w->getUi()->listWidget);
    QListWidgetItem* print =new QListWidgetItem(w->tr("+Print"),  w->getUi()->listWidget);
    QListWidgetItem* ret =new QListWidgetItem(w->tr("+Return"),  w->getUi()->listWidget);
    QListWidgetItem* start =new QListWidgetItem(w->tr("+Start"),  w->getUi()->listWidget);
    QListWidgetItem* ifNode = new QListWidgetItem(w->tr("+If"),  w->getUi()->listWidget);
    QListWidgetItem* cond =new QListWidgetItem(w->tr("+Condition"),  w->getUi()->listWidget);
    QListWidgetItem* elseNode =new QListWidgetItem(w->tr("+Else"), w->getUi()->listWidget);
    QListWidgetItem* body =new QListWidgetItem(w->tr("+BodyNode"),  w->getUi()->listWidget);
    QListWidgetItem* forNode =new QListWidgetItem(w->tr("+ForNoode"),  w->getUi()->listWidget);
    QListWidgetItem* inc =new QListWidgetItem(w->tr("+IncrementNode"),  w->getUi()->listWidget);
    QListWidgetItem* init =new QListWidgetItem(w->tr("+ForInicializeNode"),  w->getUi()->listWidget);
    QListWidgetItem* whileNode =new QListWidgetItem(w->tr("+While"),  w->getUi()->listWidget);
    QListWidgetItem* varNode =new QListWidgetItem(w->tr("+VarNode"),  w->getUi()->listWidget);
    QListWidgetItem* vectorNode = new QListWidgetItem(w->tr("+VectorNode"),  w->getUi()->listWidget);
    QListWidgetItem* VectorOperations = new QListWidgetItem(w->tr("+VectorOperations"),  w->getUi()->listWidget);
    QListWidgetItem* vece = new QListWidgetItem(w->tr("+GreaterThan"),  w->getUi()->listWidget);
    QListWidgetItem* i = new QListWidgetItem(w->tr("+BinaryAnd"),  w->getUi()->listWidget);
    QListWidgetItem* ili = new QListWidgetItem(w->tr("+BinaryOr"),  w->getUi()->listWidget);
    QListWidgetItem* jednako = new QListWidgetItem(w->tr("+BinaryEqual"),  w->getUi()->listWidget);
    QListWidgetItem* lessEq = new QListWidgetItem(w->tr("+BinaryLessEq"),  w->getUi()->listWidget);
    QListWidgetItem* greaterEq = new QListWidgetItem(w->tr("+BinaryGreaterEq"),  w->getUi()->listWidget);
    QListWidgetItem* stackNode = new QListWidgetItem(w->tr("+StackNode"),  w->getUi()->listWidget);
    QListWidgetItem* stackOperations = new QListWidgetItem(w->tr("+StackOperations"), w->getUi()->listWidget);
    QListWidgetItem* queueNode = new QListWidgetItem(w->tr("+QueueNode"),  w->getUi()->listWidget);
    QListWidgetItem* queueOperations = new QListWidgetItem(w->tr("+QueueOperations"),  w->getUi()->listWidget);
    QListWidgetItem* endOfStatement = new QListWidgetItem(w->tr("+EndOfStatement"), w->getUi()->listWidget);

    w->_functionList.append(*plus);
    w->_functionList.append(*minus);
    w->_functionList.append(*mul);
    w->_functionList.append(*less);
    w->_functionList.append(*input);
    w->_functionList.append(*print);
    w->_functionList.append(*ret);
    w->_functionList.append(*start);
    w->_functionList.append(*ifNode);
    w->_functionList.append(*cond);
    w->_functionList.append(*elseNode);
    w->_functionList.append(*body);
    w->_functionList.append(*forNode);
    w->_functionList.append(*inc);
    w->_functionList.append(*init);
    w->_functionList.append(*whileNode);
    w->_functionList.append(*varNode);
    w->_functionList.append(*vece);
    w->_functionList.append(*i);
    w->_functionList.append(*ili);
    w->_functionList.append(*jednako);
    w->_functionList.append(*lessEq);
    w->_functionList.append(*greaterEq);
    w->_functionList.append(*vectorNode);
    w->_functionList.append(*VectorOperations);
    w->_functionList.append(*stackNode);
    w->_functionList.append(*stackOperations);
    w->_functionList.append(*queueNode);
    w->_functionList.append(*queueOperations);
    w->_functionList.append(*endOfStatement);

}

void putNode(QListWidgetItem* item,QMainWindow* m,QString s)
{
    QListWidgetItem* variable;
    MainWindow *w = static_cast<MainWindow*>(m);

    if(item->text().compare("+BinarySum") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_plus", 3, 1,{}, w->getParser(), w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("plus"));
    }else if(item->text().compare("+BinaryMInus") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_minus", 3, 1,{}, w->getParser(), w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("minus"));
    }else if(item->text().compare("+BinaryMUltiply") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_puta", 3, 1,{},w->getParser(),w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("MulNode"));
    }else if(item->text().compare("+LessThan") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_manje", 3, 1,{}, w->getParser(), w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("LTNODE"));
    }else if(item->text().compare("+Input") == 0){
        InputNode* n = new InputNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("InputNode"));
    }else if(item->text().compare("+Print") == 0){
        PrintNode* n = new PrintNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("PrintNode"));
    }else if(item->text().compare("+Return") == 0){
        ReturnNode* n = new ReturnNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("ReturnNode"));
    }else if(item->text().compare("+Start") == 0){
        StartNode* n = new StartNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("StartNode"));
        w->getParser()->addNewStart(n);
    }else if(item->text().compare("+If") == 0){
        IfNode* n = new IfNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("IfNode"));
    }else if(item->text().compare("+Condition") == 0){
       ConditionNode* n = new ConditionNode();
       w->getUi()->StagingArea->addWidget(n);
       w->getParser()->addNode(n, new QString("ConditionNode"));
    }else if(item->text().compare("+Else") == 0){
        ElseNode* n = new ElseNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("ElseNode"));
     }else if(item->text().compare("+BodyNode") == 0){
        BodyNode* n = new BodyNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("BodyNode"));
     }else if(item->text().compare("+ForNoode") == 0){
        ForNode* n = new ForNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("ForNode"));
    }else if(item->text().compare("+IncrementNode") == 0){
        IncrementNode* n = new IncrementNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("IncrementNode"));
    }else if(item->text().compare("+ForInicializeNode") == 0){
        ForInicializeNode* n = new ForInicializeNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("ForInicializeNode"));
    }else if(item->text().compare("+While") == 0){
        WhileNode* n = new WhileNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("WhileNode"));
    }else if(item->text().compare("+VarNode") == 0){
        VarNode* n = new VarNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("VarNode"));
        variable = new QListWidgetItem(w->tr(n->getNodeId().toUtf8().constData()), w->getUi()->listVars);
        w->_inicializedVars.append(variable);
    }else if(item->text().compare("+GreaterThan") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_vece", 3, 1,{}, w->getParser(), w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("VeceNode"));
    }else if(item->text().compare("+BinaryAnd") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_i", 3, 1,{}, w->getParser(), w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("INode"));
     }else if(item->text().compare("+BinaryOr") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_ili", 3, 1,{}, w->getParser(), w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("IliNode"));
    }else if(item->text().compare("+BinaryEqual") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_jednako", 3, 1,{}, w->getParser(), w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("JednakoNode"));
    }else if(item->text().compare("+BinaryLessEq") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_manjeJednako", 3, 1,{}, w->getParser(), w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("MJNode"));
    }else if(item->text().compare("+BinaryGreaterEq") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_veceJednako", 3, 1,{}, w->getParser(), w->getUi()->StagingArea);
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("VJNode"));
    }else if(item->text().compare("+VectorNode") == 0){
        VectorNode* n = new VectorNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("VectorNode"));
        variable = new QListWidgetItem(w->tr(n->getNodeId().toUtf8().constData()), w->getUi()->listVars);
        w->_inicializedVars.append(variable);
    }else if(item->text().compare("+VectorOperations") == 0){
        VectorOperations* n = new VectorOperations();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("VectorOperations"));
    }else if(item->text().compare("+StackNode") == 0){
        StackNode* n = new StackNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("StackNode"));
        variable = new QListWidgetItem(w->tr(n->getNodeId().toUtf8().constData()), w->getUi()->listVars);
        w->_inicializedVars.append(variable);
    }else if(item->text().compare("+StackOperations") == 0){
        StackOperations* n = new StackOperations();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("StackOperations"));
    }else if(item->text().compare("+QueueNode") == 0){
        QueueNode* n = new QueueNode();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("QueueNode"));
        variable = new QListWidgetItem(w->tr(n->getNodeId().toUtf8().constData()), w->getUi()->listVars);
        w->_inicializedVars.append(variable);
    }else if(item->text().compare("+QueueOperations") == 0){
        QueueOperations* n = new QueueOperations();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("QueueOperations"));
    }else if(item->text().compare("+EndOfStatement") == 0){
        EndOfStatement* n = new EndOfStatement();
        w->getUi()->StagingArea->addWidget(n);
        w->getParser()->addNode(n, new QString("EndOfStatement"));
    }
    //postavlja policy za meni koji se otvara desnim klikom
    for(Node *object : w->getParser()->getGraphScene() ){
        object->setContextMenuPolicy(w->contextMenuPolicy());
    }

}
