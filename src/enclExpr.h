//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_ENCLEXPR_H
#define DECAF_COMPILER_ENCLEXPR_H

#include "expr.h"
#include "globals.h"

class EnclExpr : public Expr {
private:
    class Expr *expr;

public:
    EnclExpr(class Expr *);

    Value *codegen(globals *currentGlobals);
};



#endif //DECAF_COMPILER_ENCLEXPR_H
