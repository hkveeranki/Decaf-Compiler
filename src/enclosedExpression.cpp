//
// Created by harry7 on 7/4/18.
//

#include "enclosedExpression.h"
#include "globals.h"


enclosedExpression::enclosedExpression(class Expression *expr) {
    this->expr = expr;
    this->etype = exprType::enclExpr;
}

Value *enclosedExpression::generateCode(globals *currentGlobals) {
    return expr->generateCode(currentGlobals);
}
