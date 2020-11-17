#include "./headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem* plus = new QListWidgetItem(tr("plus"), ui->listWidget);
    QListWidgetItem* minus =new QListWidgetItem(tr("minus"), ui->listWidget);

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
   }else if(ui->listWidget->item(1) == item){
       std::cout<<"minus"<<std::endl;
   }

   Node* n3 = new Node(nullptr, 2);
   ui->StagingArea->layout()->addWidget(n3);

}


