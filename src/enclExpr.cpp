//
// Created by harry7 on 7/4/18.
//

#include "enclExpr.h"
#include "globals.h"


EnclExpr::EnclExpr(class Expr *expr) {
    this->expr = expr;
    this->etype = exprType::enclExpr;
}

Value *EnclExpr::codegen(globals *currentGlobals) {
    return expr->codegen(currentGlobals);
}
