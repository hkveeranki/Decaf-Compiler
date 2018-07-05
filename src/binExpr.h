//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_BINEXPR_H
#define DECAF_COMPILER_BINEXPR_H

#include <string>
#include "expr.h"
#include "globals.h"

using namespace std;

class binExpr : public Expr {
private:
    class Expr *lhs; /* left hand side */
    class Expr *rhs; /* right hand side */
    string opr; /* operator in between */
public:
    binExpr(class Expr *, string, class Expr *);

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_BINEXPR_H
