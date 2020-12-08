#include "./headers/InputNode.h"

/*
 * Cvor koji omogucava input. Zapravo je samo text editor.
 * Nasledjuje klasu Node.
 * Ima izlaz koji se moze povezati sa printom, ili sa ulazom u neku drugu funkciju.
 * Ne sadrzi ulaze.
*/


InputNode::InputNode():Node("input", 0, 1), manualInput(false), fileInput(false), input(nullptr)
{
    setMinimumSize(80,80);
    setMaximumSize(300, 200);
    //setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(98, 9, 77, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");


    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());

    QRadioButton* fileInputRadioButton = new QRadioButton("Input from file",this);
    QRadioButton *manualInputRadioButton = new QRadioButton("Manula input",this);

    QButtonGroup *choice = new QButtonGroup(this);
    choice->addButton(fileInputRadioButton, 1);
    choice->addButton(manualInputRadioButton, 2 );

    connect(choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            [=](){

        if(this->fileInput || this->manualInput){
            if(this->input != nullptr){
                this->input->deleteLater();
                this->input = nullptr;
            }
            this->fileInput = false;
            this->manualInput = false;
        }

        int choosen = choice->checkedId();
        if(choosen == 1){
            QTextEdit* fileEdit = new QTextEdit();
            const QString* font = new QString("Courier New");
            const QString* placeHolder = new QString("Enter file location here...");
            fileEdit->setFontFamily(*font);
            fileEdit->setPlaceholderText(*placeHolder);
            //QString input = lineEdit->text();
            //this->fileName = new QString(input);
            Node* parent = static_cast<Node*>(choice->parent());
            QGridLayout* layout = static_cast<QGridLayout*>(parent->layout());
            layout->addWidget(fileEdit,4,0);
            this->fileInput = true;
            this->input = fileEdit;
        }
    });
    connect(choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            [=](){

        if(this->manualInput){
            if(this->input != nullptr){
                this->input->deleteLater();
                this->input = nullptr;
                this->manualInput = false;
            }
            if(this->fileInput){
                this->input->deleteLater();
                this->input = nullptr;
                this->fileInput = false;
            }
        }

        int choosen = choice->checkedId();
        if(choosen == 2){
            QTextEdit* edit = new QTextEdit();
            const QString* font = new QString("Courier New");
            const QString* placeHolder = new QString("Enter text here...");
            edit->setFontFamily(*font);
            edit->setPlaceholderText(*placeHolder);
            Node* parent = static_cast<Node*>(choice->parent());
            QGridLayout* layout = static_cast<QGridLayout*>(parent->layout());
            layout->addWidget(edit,4,0);
            this->manualInput = true;
            this->input = edit;
        }
    });
    layout->addWidget(fileInputRadioButton,2,0);
    layout->addWidget(manualInputRadioButton,3,0);
}

void InputNode::resetInput()
{
    if(this->manualInput){
        if(this->input != nullptr){
            this->input->deleteLater();
            this->input = nullptr;
            this->manualInput = false;
        }
        if(this->fileInput){
            this->input->deleteLater();
            this->input = nullptr;
            this->fileInput = false;
        }
    }
}

QString InputNode::getCodeForNode()
{
    QString text = "#include<isotream>\n#include<string>\n\nint main(){\n";
    qDebug()<<"Input";
    return text;
}

QString* InputNode::getText()
{
    return text;
}
