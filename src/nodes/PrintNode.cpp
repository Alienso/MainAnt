#include "./headers/nodesHeaders/PrintNode.h"

/*
 * Cvor koji omogucava ispis. ON je zapravo sacinjen od text editora u koji ne moze da se pise iz aplikacije.
 * Sadrzi place holder, a sadrzaj teksta se moze iz koda menjati korestieci metod setText("Neki string").
 * Nasledjuje klasu Node.
 * Sadrzi jedan ulaz.
*/

PrintNode::PrintNode() : Node("print", 1, 1, {"flow/input"})
{
    setMinimumSize(200,200);
    setStyleSheet ("background-color: rgba(105, 50, 129, 1);"
                   "border: 1px solid rgba(194, 145, 211, 1);"
                   "border-radius:5px;");
    setColors({'s','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();

    QRadioButton* fileInputRadioButton = new QRadioButton("Input from file",this);
    QRadioButton *manualInputRadioButton = new QRadioButton("Manula input",this);
    QRadioButton *printMyInputButton = new QRadioButton("Print my input", this);

    QButtonGroup *choice = new QButtonGroup(this);
    choice->addButton(printMyInputButton, 1);
    choice->addButton(fileInputRadioButton, 2);
    choice->addButton(manualInputRadioButton, 3);

    printMyInputButton->setChecked(true);
    this->printMyInput = true;

    connect(choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            [=](){

        if(this->printMyInput){
            this->printMyInput = false;
        }

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
            this->printMyInput = true;
        }
        else if(choosen == 2){
            QTextEdit* fileEdit = new QTextEdit();
            const QString* font = new QString("Courier New");
            const QString* placeHolder = new QString("Enter file location here...");
            fileEdit->setFontFamily(*font);
            fileEdit->setPlaceholderText(*placeHolder);
            //QString input = lineEdit->text();
            //this->fileName = new QString(input);
            Node* parent = static_cast<Node*>(choice->parent());
            QGridLayout* layout = static_cast<QGridLayout*>(parent->layout());
            layout->addWidget(fileEdit,5,1);
            this->fileInput = true;
            this->input = fileEdit;
        }else if(choosen == 3){
            QTextEdit* edit = new QTextEdit();
            const QString* font = new QString("Courier New");
            const QString* placeHolder = new QString("Enter text here...");
            edit->setFontFamily(*font);
            edit->setPlaceholderText(*placeHolder);
            Node* parent = static_cast<Node*>(choice->parent());
            QGridLayout* layout = static_cast<QGridLayout*>(parent->layout());
            layout->addWidget(edit,5,1);
            this->manualInput = true;
            this->input = edit;
        }


    });

    layout->addWidget(printMyInputButton, 2, 1);
    layout->addWidget(fileInputRadioButton,3,1);
    layout->addWidget(manualInputRadioButton,4,1);
}

QString PrintNode::getCodeForNode()
{
    QString text;
    if(this->printMyInput){
        return "std::cout<<";
    }
    text.push_back("std::cout<<\"");
    if(this->manualInput){
       QString tmpText = this->input->toPlainText();
       text.push_back(tmpText);
    }else if(this->fileInput){
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
