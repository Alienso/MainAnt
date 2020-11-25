#include "./headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,p(new Parser)
{
    ui->setupUi(this);

    QListWidgetItem* plus = new QListWidgetItem(tr("+BinarySum"), ui->listWidget);
    QListWidgetItem* minus =new QListWidgetItem(tr("+BinaryMInus"), ui->listWidget);
    QListWidgetItem* mul =new QListWidgetItem(tr("+BinaryMUltiply"), ui->listWidget);
    QListWidgetItem* less =new QListWidgetItem(tr("+LessThan"), ui->listWidget);
    QListWidgetItem* input =new QListWidgetItem(tr("+Input"), ui->listWidget);
    QListWidgetItem* inputFromFile =new QListWidgetItem(tr("+InputFromFile"), ui->listWidget);
    QListWidgetItem* print =new QListWidgetItem(tr("+Print"), ui->listWidget);
    QListWidgetItem* ret =new QListWidgetItem(tr("+Return"), ui->listWidget);
    QListWidgetItem* start =new QListWidgetItem(tr("+Start"), ui->listWidget);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putNode(QListWidgetItem*)));
    ui->StagingArea->setLayout(new QFormLayout());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::putNode(QListWidgetItem* item)
{
   if(ui->listWidget->item(0) == item){
       //std::cout<<"plus"<<std::endl;
       Node* n = new Node("plus", 2, 1, nullptr);
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("PlusNode"));
   }else if(ui->listWidget->item(1) == item){
       //std::cout<<"minus"<<std::endl;
       Node* n = new Node("minus", 2, 1, nullptr);
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("MinusNode"));
   }else if(ui->listWidget->item(2) == item){
       //std::cout<<"puta"<<std::endl;
       Node* n = new Node("puta", 2, 1, nullptr);
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("MulNode"));
   }else if(ui->listWidget->item(3) == item){
       //std::cout<<"manje"<<std::endl;
       Node* n = new Node("manje", 2, 1, nullptr);
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("LTNODE"));
   }else if(ui->listWidget->item(4) == item){
       InputNode* n = new InputNode();
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("InputNode"));
   }else if(ui->listWidget->item(5) == item){
       InputfromFile* n = new InputfromFile();
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("InputformFile"));
   }else if(ui->listWidget->item(6) == item){
       PrintNode* n = new PrintNode();
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("PrintNode"));
   }else if(ui->listWidget->item(7) == item){
       ReturnNode* n = new ReturnNode();
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("ReturnNode"));
   }else if(ui->listWidget->item(8) == item){
       StartNode* n = new StartNode();
       ui->StagingArea->addWidget(n);
       p->addNode(n, new QString("StartNode"));
   }
    //postavlja policy za meni koji se otvara desnim klikom
    for(Node *object : p->getGraph()){
        object->setContextMenuPolicy(contextMenuPolicy());
    }

   QMap<QString, Node*> graf = p->getGraphScene();
   QList<QString> kljuc = graf.keys();
   for(auto item : kljuc){
        std::cout<<item.toUtf8().constData()<<std::endl;
    }

}

//Evo nacina da prepoznate na sta ste kliknuli iz liste
/*
void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item){
    ui->StagingArea->layout()->addWidget(new Node(item->text(),2,1, nullptr));
}
*/
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

