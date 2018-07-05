//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_BLOCK_H
#define DECAF_COMPILER_BLOCK_H

#include "stmt.h"
#include "globals.h"

class Block : public Stmt {
private:
    class varDecls *decls_list; /* list of variable declarations */
    class Stmts *stmts_list; /* list of statement declarations */
public:
    Block(class varDecls *, class Stmts *);

    bool has_return();

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_BLOCK_H
