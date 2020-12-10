#include "./headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , p(new Parser)
{
    ui->setupUi(this);
    setWindowTitle(":)");
    setWindowIcon(QIcon("./icon.icon")); //TODO program se izvrsava iz foldera buildmainant...

    functionsListInit();

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putNode(QListWidgetItem*)));
    connect(ui->searchBar,&QLineEdit::textChanged,this,&MainWindow::filterFunctions);
    //connect(ui->horizontalLayout_2->, SIGNAL(), this, SLOT(on_actionRun_triggered()));
    ui->StagingArea->setLayout(new CustomLayout(1));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::putNode(QListWidgetItem* item)
{
    QListWidgetItem* variable;
    if(item->text().compare("+BinarySum") == 0){
        //std::cout<<"plus"<<std::endl;
        BinaryFunction* n = new BinaryFunction("Binary_plus", 3, 1,{}, p, ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("plus"));
    }else if(item->text().compare("+BinaryMInus") == 0){
        //std::cout<<"minus"<<std::endl;
        BinaryFunction* n = new BinaryFunction("Binary_minus", 3, 1,{}, p, ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("minus"));
    }else if(item->text().compare("+BinaryMUltiply") == 0){
        //std::cout<<"puta"<<std::endl;
        BinaryFunction* n = new BinaryFunction("Binary_puta", 3, 1,{},p,ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("MulNode"));
    }else if(item->text().compare("+LessThan") == 0){
        //std::cout<<"manje"<<std::endl;
        BinaryFunction* n = new BinaryFunction("Binary_manje", 3, 1,{}, p, ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("LTNODE"));
    }else if(item->text().compare("+Input") == 0){
        InputNode* n = new InputNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("InputNode"));
    }else if(item->text().compare("+Print") == 0){
        PrintNode* n = new PrintNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("PrintNode"));
    }else if(item->text().compare("+Return") == 0){
        ReturnNode* n = new ReturnNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("ReturnNode"));
    }else if(item->text().compare("+Start") == 0){
        StartNode* n = new StartNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("StartNode"));
        p->addNewStart(n);
    }else if(item->text().compare("+If") == 0){
        IfNode* n = new IfNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("IfNode"));
    }else if(item->text().compare("+Condition") == 0){
       ConditionNode* n = new ConditionNode();
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("ConditionNode"));
    }else if(item->text().compare("+Else") == 0){
        ElseNode* n = new ElseNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("ElseNode"));
     }else if(item->text().compare("+BodyNode") == 0){
        BodyNode* n = new BodyNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("BodyNode"));
     }else if(item->text().compare("+ForNoode") == 0){
        ForNode* n = new ForNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("ForNode"));
    }else if(item->text().compare("+IncrementNode") == 0){
        IncrementNode* n = new IncrementNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("IncrementNode"));
    }else if(item->text().compare("+ForInicializeNode") == 0){
        ForInicializeNode* n = new ForInicializeNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("ForInicializeNode"));
    }else if(item->text().compare("+While") == 0){
        WhileNode* n = new WhileNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("WhileNode"));
    }else if(item->text().compare("+VarNode") == 0){
        VarNode* n = new VarNode();
        ui->StagingArea->addWidget(n);
        variable = new QListWidgetItem(tr("V"), ui->listVars);
        p->addNode(n, new QString("VarNode"));
    }else if(item->text().compare("+GreaterThan") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_vece", 3, 1,{}, p, ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("VeceNode"));
    }else if(item->text().compare("+BinaryAnd") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_i", 3, 1,{}, p, ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("INode"));
     }else if(item->text().compare("+BinaryOr") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_ili", 3, 1,{}, p, ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("IliNode"));
    }else if(item->text().compare("+BinaryEqual") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_jednako", 3, 1,{}, p, ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("JednakoNode"));
    }else if(item->text().compare("+BinaryLessEq") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_manjeJednako", 3, 1,{}, p, ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("MJNode"));
    }else if(item->text().compare("+BinaryGreaterEq") == 0){
        BinaryFunction* n = new BinaryFunction("Binary_veceJednako", 3, 1,{}, p, ui->StagingArea);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("VJNode"));
    }else if(item->text().compare("+VectorNode") == 0){
        VectorNode* n = new VectorNode();
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("VectorNode"));
    }
    //postavlja policy za meni koji se otvara desnim klikom
    for(Node *object : p->getGraphScene() ){
        object->setContextMenuPolicy(contextMenuPolicy());
    }

    /*QMap<QString, Node*> graf = p->getGraphScene();
    QList<QString> kljuc = graf.keys();
    for(auto item : kljuc){
        std::cout<<item.toUtf8().constData()<<std::endl;
    }*/

    for(auto start : p->getStartNodes()){
        std::cout<<"OK"<<std::endl;
    }
    std::cout<<"---------"<<std::endl;
    std::cout<<item->text().toUtf8().constData()<<'\n';

}

//Evo nacina da prepoznate na sta ste kliknuli iz liste
/*
void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item){
    ui->StagingArea->layout()->addWidget(new Node(item->text(),2,1, nullptr));
}
*/

void MainWindow::functionsListInit(){
    QListWidgetItem* plus = new QListWidgetItem(tr("+BinarySum"), ui->listWidget);
    QListWidgetItem* minus =new QListWidgetItem(tr("+BinaryMInus"), ui->listWidget);
    QListWidgetItem* mul =new QListWidgetItem(tr("+BinaryMUltiply"), ui->listWidget);
    QListWidgetItem* less =new QListWidgetItem(tr("+LessThan"), ui->listWidget);
    QListWidgetItem* input =new QListWidgetItem(tr("+Input"), ui->listWidget);
    QListWidgetItem* print =new QListWidgetItem(tr("+Print"), ui->listWidget);
    QListWidgetItem* ret =new QListWidgetItem(tr("+Return"), ui->listWidget);
    QListWidgetItem* start =new QListWidgetItem(tr("+Start"), ui->listWidget);
    QListWidgetItem* ifNode = new QListWidgetItem(tr("+If"), ui->listWidget);
    QListWidgetItem* cond =new QListWidgetItem(tr("+Condition"), ui->listWidget);
    QListWidgetItem* elseNode =new QListWidgetItem(tr("+Else"), ui->listWidget);
    QListWidgetItem* body =new QListWidgetItem(tr("+BodyNode"), ui->listWidget);
    QListWidgetItem* forNode =new QListWidgetItem(tr("+ForNoode"), ui->listWidget);
    QListWidgetItem* inc =new QListWidgetItem(tr("+IncrementNode"), ui->listWidget);
    QListWidgetItem* init =new QListWidgetItem(tr("+ForInicializeNode"), ui->listWidget);
    QListWidgetItem* whileNode =new QListWidgetItem(tr("+While"), ui->listWidget);
    QListWidgetItem* varNode =new QListWidgetItem(tr("+VarNode"), ui->listWidget);
    QListWidgetItem* vectorNode = new QListWidgetItem(tr("+VectorNode"), ui->listWidget);
    QListWidgetItem* vece = new QListWidgetItem(tr("+GreaterThan"), ui->listWidget);
    QListWidgetItem* i = new QListWidgetItem(tr("+BinaryAnd"), ui->listWidget);
    QListWidgetItem* ili = new QListWidgetItem(tr("+BinaryOr"), ui->listWidget);
    QListWidgetItem* jednako = new QListWidgetItem(tr("+BinaryEqual"), ui->listWidget);
    QListWidgetItem* lessEq = new QListWidgetItem(tr("+BinaryLessEq"), ui->listWidget);
    QListWidgetItem* greaterEq = new QListWidgetItem(tr("+BinaryGreaterEq"), ui->listWidget);

    this->_functionList.append(*plus);
    this->_functionList.append(*minus);
    this->_functionList.append(*mul);
    this->_functionList.append(*less);
    this->_functionList.append(*input);
    this->_functionList.append(*print);
    this->_functionList.append(*ret);
    this->_functionList.append(*start);
    this->_functionList.append(*ifNode);
    this->_functionList.append(*cond);
    this->_functionList.append(*elseNode);
    this->_functionList.append(*body);
    this->_functionList.append(*forNode);
    this->_functionList.append(*inc);
    this->_functionList.append(*init);
    this->_functionList.append(*whileNode);
    this->_functionList.append(*varNode);
    this->_functionList.append(*vece);
    this->_functionList.append(*i);
    this->_functionList.append(*ili);
    this->_functionList.append(*jednako);
    this->_functionList.append(*lessEq);
    this->_functionList.append(*greaterEq);
    this->_functionList.append(*vectorNode);

}

//*File->Open Ucitava se tekstualni fajl.
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open MainAnt"), "",
                                                    tr("MainAnt (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        //U in fajlu nam se nalazi sadrzaj ucitane datoteke
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        /*ovde bi trebalo u osnovi da se izvrsi nesto ovako:
        in>> staging area;
        */
    }
}

//*File->Save Cuva se tekstualni fajl.
void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save MainAnt File"), "",
                                                    tr("MainAnt (*.mant);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        //Preko out-a pisemo u fajl koji ce biti sacuvan. Verovatno necete moci da procitate kada otvorite jer je QString upisan.
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << QString("Projekat MainAnt");
    }
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionRun_triggered()
{
    QString p1 = p->traverseGraph();
    if(p1 == QString::fromStdString("Fali")){
        qDebug() << "Fail";
    }
    else
        qDebug() << p1;

}

void MainWindow::filterFunctions(){

    ui->listWidget->clear();
    for (int i=0;i<_functionList.length();i++)
        if (this->_functionList[i].text().contains(ui->searchBar->text(),Qt::CaseInsensitive))
            ui->listWidget->addItem(_functionList[i].text());
}

