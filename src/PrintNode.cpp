#include "./headers/PrintNode.h"

/*
 * Cvor koji omogucava ispis. ON je zapravo sacinjen od text editora u koji ne moze da se pise iz aplikacije.
 * Sadrzi place holder, a sadrzaj teksta se moze iz koda menjati korestieci metod setText("Neki string").
 * Nasledjuje klasu Node.
 * Sadrzi jedan ulaz.
*/

PrintNode::PrintNode() : Node("print", 1, 1)
{
    setMinimumSize(200,300);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(105, 50, 129, 1);"
                   "border: 1px solid rgba(194, 145, 211, 1);");
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
QString PrintNode::getCodeForNode()
{
    QString text;
        text.push_back("std::cout<<\"");
        if(this->manualInput){
            QString tmpText = this->input->toPlainText();
            text.push_back(tmpText);
        }
        if(this->fileInput){
            QString fileName = this->input->toPlainText();
            std::fstream fdata(fileName.toUtf8().constData());

            char c;
            while(fdata.get(c)){
                text.push_back(c);
            }

        }
        text = text.simplified();
        text.push_back("\"<<std::endl;\n");
        return text;

}
