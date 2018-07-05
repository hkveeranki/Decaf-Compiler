//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_BLOCK_H
#define DECAF_COMPILER_BLOCK_H

#include "statement.h"
#include "globals.h"

class Block : public Statement {
private:
    class variableDeclarations *decls_list; /* list of variable declarations */
    class Statements *stmts_list; /* list of statement declarations */
public:
    Block(class variableDeclarations *, class Statements *);

    bool has_return();

    Value *generateCode(globals *currentGlobals);
};


#endif
