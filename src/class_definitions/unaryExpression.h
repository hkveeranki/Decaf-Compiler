//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_UNARYEXPRESSION_H
#define DECAF_COMPILER_UNARYEXPRESSION_H

#include "expression.h"
#include "globals.h"
#include <string>

class unaryExpression : public Expression {
private:
    class Expression *body; /* body of expression */
    std::string opr; /* Unary Expression */
public:
    unaryExpression(std::string, class Expression *);

    Value *generateCode(globals *currentGlobals);
};


#endif
