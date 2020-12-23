#ifndef BINARYFUNCTION
#define BINARYFUNCTION

#include <QString>
#include <QWidget>

#include "./headers/Node.h"


class BinaryFunction : public Node
{
public:
    BinaryFunction(QString _name,int ninputs,int noutputs, QVector<QString> args = {}, Parser * p_ = nullptr,QWidget* parent = nullptr);

    QString getCodeForNode() override;
};



#endif // BINARYFUNCTION

