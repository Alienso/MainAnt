#include "./headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem* plus = new QListWidgetItem(tr("+BinarySum"), ui->listWidget);
    QListWidgetItem* minus =new QListWidgetItem(tr("+BinaryMInus"), ui->listWidget);
    QListWidgetItem* mul =new QListWidgetItem(tr("+BinaryMUltiply"), ui->listWidget);
    QListWidgetItem* less =new QListWidgetItem(tr("+LessThan"), ui->listWidget);
    QListWidgetItem* input =new QListWidgetItem(tr("+Input"), ui->listWidget);
    QListWidgetItem* print =new QListWidgetItem(tr("+Print"), ui->listWidget);

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
       std::cout<<"plus"<<std::endl;

       Node* n3 = new Node(nullptr, 2);
       ui->StagingArea->layout()->addWidget(n3);
   }else if(ui->listWidget->item(1) == item){
       std::cout<<"minus"<<std::endl;

       Node* n3 = new Node(nullptr, 2);
       ui->StagingArea->layout()->addWidget(n3);
   }else if(ui->listWidget->item(2) == item){
       std::cout<<"puta"<<std::endl;

       Node* n3 = new Node(nullptr, 2);
       ui->StagingArea->layout()->addWidget(n3);
   }else if(ui->listWidget->item(3) == item){
       std::cout<<"manje"<<std::endl;

       Node* n3 = new Node(nullptr, 2);
       ui->StagingArea->layout()->addWidget(n3);
   }else if(ui->listWidget->item(4) == item){
       InputNode* n = new InputNode();
       ui->StagingArea->layout()->addWidget(n);
   }else if(ui->listWidget->item(5) == item){
       PrintNode* n = new PrintNode();
       ui->StagingArea->layout()->addWidget(n);
   }

}
//Evo nacina da prepoznate na sta ste kliknuli iz liste
/*
void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item){
    ui->StagingArea->layout()->addWidget(new Node(item->text(),nullptr,2,1));
}
*/
