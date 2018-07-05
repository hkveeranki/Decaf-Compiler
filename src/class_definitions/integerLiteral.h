//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_INTEGERLITERAL_H
#define DECAF_COMPILER_INTEGERLITERAL_H

#include "literal.h"
#include "globals.h"

class integerLiteral : public Literal {
private:
    int value;
public:
    explicit integerLiteral(int);

    int getValue();

    Value *generateCode(globals *currentGlobals);
};


#endif
