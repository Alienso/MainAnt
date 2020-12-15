#include "./headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , p(new Parser)
{
    ui->setupUi(this);
    setWindowTitle(":)");
    setWindowIcon(QIcon("./icon.ico")); //TODO program se izvrsava iz foldera buildmainant...

    functionsListInit(this,"main");

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onPutNode(QListWidgetItem*)));
    connect(ui->listVars, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putVar(QListWidgetItem*)));
    connect(ui->searchBar,&QLineEdit::textChanged,this,&MainWindow::filterFunctions);
    //connect(ui->horizontalLayout_2->, SIGNAL(), this, SLOT(on_actionRun_triggered()));
    ui->StagingArea->setLayout(new CustomLayout(1));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::putVar(QListWidgetItem *item)
{
    for(int i =0; i<_inicializedVars.size(); i++)
    {
        if(_inicializedVars[i] == item){
            VariableReferenceNode* n = new VariableReferenceNode(item->text());
            n->setRefNameId(item->text());
            ui->StagingArea->addWidget(n);
            p->addNode(n, new QString("VariableReferenceNode"));
        }
    }
}

void MainWindow::onPutNode(QListWidgetItem* item){
    putNode(item,this,"");
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
    QString p1 = p->compileAndRun();
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


void MainWindow::on_AddFunction_clicked()
{
    qDebug()<<"+Function";
    FunctionWindow *f=new FunctionWindow(nullptr);
    QMessageBox msgBox;
    msgBox.setText("To save the changes you have made chose 'Build->Add Function'.");
    f->show();
    msgBox.exec();
}

Ui::MainWindow* MainWindow::getUi(){
    return ui;
}

Parser* MainWindow::getParser(){
    return p;
}
