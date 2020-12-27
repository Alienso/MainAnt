#ifndef BINARYFUNCTION
#define BINARYFUNCTION

#include <QString>
#include <QWidget>

#include "./headers/Node.h"


class BinaryFunction : public Node
{
public:
    BinaryFunction(QString _name,int ninputs,int noutputs);

    QString getCodeForNode() override;
};



#endif // BINARYFUNCTION

