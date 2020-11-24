#ifndef INPUTFROMFILE_H
#define INPUTFROMFILE_H

#include <QString>
#include <QLineEdit>
#include "./headers/Node.h"

class InputfromFile : public Node
{
public:
    InputfromFile();

private:
    QString *fileName = nullptr;
};

#endif // INPUTFROMFILE_H
