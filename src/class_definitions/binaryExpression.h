//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_BINARYEXPR_H
#define DECAF_COMPILER_BINARYEXPR_H

#include <string>
#include "expression.h"
#include "globals.h"

using namespace std;

class binaryExpression : public Expression {
private:
    class Expression *lhs; /* left hand side */
    class Expression *rhs; /* right hand side */
    string opr; /* operator in between */
public:
    binaryExpression(class Expression *, string, class Expression *);

    Value *generateCode(globals *currentGlobals);
};


#endif
