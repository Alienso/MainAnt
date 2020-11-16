#include "./headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Node* n = new Node(nullptr,3);
    ui->StagingArea->setLayout(new QFormLayout());
    ui->StagingArea->layout()->addWidget(n);
}

MainWindow::~MainWindow()
{
    delete ui;
}

