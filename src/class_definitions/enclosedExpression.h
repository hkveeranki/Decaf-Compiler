/**
 * class to deal with enclosed expressions i.e expressions enclosed within braces
 */

#ifndef DECAF_COMPILER_ENCLOSEDEXPRESSION_H
#define DECAF_COMPILER_ENCLOSEDEXPRESSION_H

#include "expression.h"
#include "constructs.h"

class enclosedExpression : public Expression {
private:
    /* expression which is enclosed */
    class Expression *expr;

public:
    explicit enclosedExpression(class Expression *);

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
