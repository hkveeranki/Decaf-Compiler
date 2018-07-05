//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_FORSTMT_H
#define DECAF_COMPILER_FORSTMT_H

#include <string>
#include "block.h"
#include "expr.h"
#include "stmt.h"

class forStmt : public Stmt {
private:
    std::string var;/* variable to be initialised */
    class Expr *init; /* Value for initialisation */
    class Expr *condition; /* condition for loop */
    class Block *body; /* body of the loop */
public:
    forStmt(std::string, class Expr *, class Expr *, class Block *);

    bool has_return() { this->body->has_return(); }

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_FORSTMT_H
