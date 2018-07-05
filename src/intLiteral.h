//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_INTLITERAL_H
#define DECAF_COMPILER_INTLITERAL_H

#include "literal.h"
#include "globals.h"

class intLiteral : public Literal {
private:
    int value;
public:
    explicit intLiteral(int);

    int getValue();

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_INTLITERAL_H
