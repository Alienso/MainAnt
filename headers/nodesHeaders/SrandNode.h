#ifndef SRANDNODE_H
#define SRANDNODE_H

#include <QString>
#include "./headers/Node.h"

class SrandNode : public Node{
    public:
        SrandNode();
        virtual QString getCodeForNode() override;
};

#endif // SRANDNODE_H
