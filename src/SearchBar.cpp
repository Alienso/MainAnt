#include "./headers/SearchBar.h"

SearchBar::SearchBar(QWidget *parent) : QLineEdit(parent){
    setStyleSheet("color : rgb(189, 221, 235);");
}

QVector<char>& SearchBar::storedText(){
    return this->_storedText;
}

QString SearchBar::toQString(){
    char tmp[50];
    for (int i=0;i<storedText().length();i++)
        tmp[i] = storedText()[i];
    tmp[storedText().length()] = '\0';
    return QString(tmp);
}

void SearchBar::keyPressEvent(QKeyEvent *e){
    if (e->text() == 8 && storedText().length() != 0){
        storedText().pop_back();
        setText(toQString());
        return;
    }
    if (e->text() < 32)
        return;

    storedText().push_back(e->text().toUtf8().constData()[0]);
    setText(toQString());
}
