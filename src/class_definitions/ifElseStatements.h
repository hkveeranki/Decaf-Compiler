/**
 * class to deal with if else statements in code
 */

#ifndef DECAF_COMPILER_IFELSESTATEMENT_H
#define DECAF_COMPILER_IFELSESTATEMENT_H

#include "block.h"
#include "expression.h"
#include "statement.h"

class ifElseStatements : public Statement {
private:
    /* condition for if statement */
    class Expression *condition;

    /* if block */
    class Block *if_block;

    /* else block */
    class Block *else_block;

public:
    ifElseStatements(class Expression *, class Block *, class Block *);

    Value *generateCode(Constructs *compilerConstructs) override;

    bool has_return() override;
    bool has_break() override;
    bool has_continue() override;
};


#endif
