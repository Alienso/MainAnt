#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QLineEdit>
#include <QKeyEvent>
#include <QString>

class SearchBar : public QLineEdit{

public:
    explicit SearchBar();
    explicit SearchBar(QWidget *parent);
    void keyPressEvent(QKeyEvent *e);
    QVector<char>& storedText();
    QString toQString();
private:
    QVector<char> _storedText;
};

#endif // SEARCHBAR_H
