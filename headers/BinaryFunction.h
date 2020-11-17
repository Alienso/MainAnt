#ifndef BINARYFUNCTION
#define BINARYFUNCTION

template<typename T>
class BinaryFunction{
public:
    BinaryFunction(T op1, T op2)
        :op1(op1), op2(op2)
    {};

    T BinaryFunction::plus()
    {
        return this-> op1 + this->op2;
    }

    T minus()
    {
        return this->op1 - this->op2;
    }



private:
    T op1;
    T op2;

}



#endif // BINARYFUNCTION

