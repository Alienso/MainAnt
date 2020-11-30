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

    QString getCodeForNode() override;
//ovo ce biti obrisano, sluzi za proveru
/*protected:
    void mousePressEvent(QMouseEvent *event);
    */
};



#endif // BINARYFUNCTION

