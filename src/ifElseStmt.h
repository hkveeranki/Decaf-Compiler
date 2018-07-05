//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_IFELSESTMT_H
#define DECAF_COMPILER_IFELSESTMT_H

#include "block.h"
#include "expr.h"
#include "stmt.h"

class ifElseStmt : public Stmt {
private:
    class Expr *condition; /* condition for if statement */
    class Block *if_block; /* if block */
    class Block *else_block;/* else block */
public:
    ifElseStmt(class Expr *, class Block *, class Block *);

    Value *codegen(globals *currentGlobals);

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


#endif //DECAF_COMPILER_IFELSESTMT_H
