/**
 * class to deal unary Expressions in the code
 */
#ifndef DECAF_COMPILER_UNARYEXPRESSION_H
#define DECAF_COMPILER_UNARYEXPRESSION_H

#include "expression.h"
#include "constructs.h"
#include <string>

class unaryExpression : public Expression {
private:
    /* body of expression */
    class Expression *body;

    /* Unary Expression */
    std::string opr;
public:
    unaryExpression(std::string, class Expression *);

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
