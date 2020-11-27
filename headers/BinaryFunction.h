#ifndef BINARYFUNCTION
#define BINARYFUNCTION

#include "./headers/Node.h"


template<typename T>
class BinaryFunction : public Node
{
private:

    T op1;
    T op2;
public:
    BinaryFunction(T op1, T op2)
        :op1(op1), op2(op2)
    {}

    T plusFunc()
    {
        return this-> op1 + this->op2;
    }

    T minusFunc()
    {
        return this->op1 - this->op2;
    }

    T mulFunc(){
        return this->op1 * this->op2;
    }

    T lessTHanFunc(){
        return this->op1 < this->op2;
    }
    QString getCodeForNode() override;
};



#endif // BINARYFUNCTION

