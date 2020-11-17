#ifndef BINARYFUNCTION
#define BINARYFUNCTION


template<typename T>
class BinaryFunction{
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



private:
    T op1;
    T op2;

};



#endif // BINARYFUNCTION

