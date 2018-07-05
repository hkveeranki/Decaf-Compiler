//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_UNEXPR_H
#define DECAF_COMPILER_UNEXPR_H

#include "expr.h"
#include "globals.h"
#include <string>

class unExpr : public Expr {
private:
    class Expr *body; /* body of expression */
    std::string opr; /* Unary Expression */
public:
    unExpr(std::string, class Expr *);

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_UNEXPR_H
