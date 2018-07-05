//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_ENCLOSEDEXPRESSION_H
#define DECAF_COMPILER_ENCLOSEDEXPRESSION_H

#include "expression.h"
#include "globals.h"

class enclosedExpression : public Expression {
private:
    class Expression *expr;

public:
    enclosedExpression(class Expression *);

    Value *generateCode(globals *currentGlobals);
};



#endif
