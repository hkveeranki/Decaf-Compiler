//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_IFELSESTATEMENT_H
#define DECAF_COMPILER_IFELSESTATEMENT_H

#include "block.h"
#include "expression.h"
#include "statement.h"

class ifElseStatements : public Statement {
private:
    class Expression *condition; /* condition for if statement */
    class Block *if_block; /* if block */
    class Block *else_block;/* else block */
public:
    ifElseStatements(class Expression *, class Block *, class Block *);

    Value *generateCode(globals *currentGlobals);

    bool has_return() {
        bool status = false;
        if (if_block != nullptr) {
            status = status | if_block->has_return();
        }
        if (else_block != nullptr) {
            status = status | if_block->has_return();
        }
        return status;
    }
};


#endif
