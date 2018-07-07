/**
 * Class to handle binary operator expression in the code.
 *
 */
#ifndef DECAF_COMPILER_BINARYEXPR_H
#define DECAF_COMPILER_BINARYEXPR_H

#include <string>
#include "expression.h"
#include "constructs.h"

using namespace std;

class binaryExpression : public Expression {
private:
    /* left hand side */
    class Expression *lhs;

    /* right hand side */
    class Expression *rhs;

    /* operator in between */
    string opr;
public:
    binaryExpression(class Expression *, string, class Expression *);

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
