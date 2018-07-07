/**
 * class to deal with return statements in the code
 */

#ifndef DECAF_COMPILER_RETURNSTATEMENT_H
#define DECAF_COMPILER_RETURNSTATEMENT_H

#include "expression.h"
#include "statement.h"
#include "constructs.h"

class returnStatement : public Statement {
private:
    /* Expression to be returned */
    class Expression *ret;
public:
    explicit returnStatement(class Expression *);

    Value *generateCode(Constructs *compilerConstructs) override;

    bool has_return() override { return true; }
};


#endif
