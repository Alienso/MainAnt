#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>

#include "./headers/Node.h"

class FunctionNode : public Node
{
    Q_OBJECT
public:
    FunctionNode();
    QLineEdit* FunctionName;
    QComboBox* combo;
    QPushButton *addArg;
    //Kada se ovo dugme klikne dodaju se argumenti u listu za referenciranje na njih
    QPushButton *addToVisible;
    QVector<QPushButton*> deleteButton;
    QVector<QLineEdit*> argumentsNames;
    QVector<QComboBox*> argumentsTypes;
    //do kog koeficijenta smo stigli u layoutu sa dodavanjem
    int layoutK=6;

    int getArgNum() const;
    QString getRetVal() const;


    QString getCodeForNode() override;

public slots:
    void addArgument();
    void deleteArgument();

private:
    int currWidth = 200;
    int argNum;
};

#endif // FUNCTIONNODE_H
