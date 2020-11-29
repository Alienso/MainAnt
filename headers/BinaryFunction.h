#ifndef BINARYFUNCTION
#define BINARYFUNCTION

#include <QString>
#include <QWidget>

#include "./headers/Node.h"
#include "./headers/InputNode.h"

class InputNode;
class Parser;

class BinaryFunction : public Node
{
private:
    QString op1;
    QString op2;
public:
    BinaryFunction(QString _name,int ninputs,int noutputs, Parser * p_,QWidget* parent);
    void setParameters(InputNode *op1_, InputNode *op2_);
    QString plusFunc()
    {
        return this->op1 + " + "+ this->op2 + ";\n";
    }

    QString minusFunc()
    {
        return this->op1 + " - "+ this->op2 + ";\n";
    }

    QString mulFunc(){
        return this->op1 + " * "+ this->op2 + ";\n";
    }

    QString lessTHanFunc(){
        return this->op1 + " < "+ this->op2 + ";\n";
    }
    QString getCodeForNode() override;
};



#endif // BINARYFUNCTION

