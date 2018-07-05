//
// Created by harry7 on 7/4/18.
//

#include "unExpr.h"
#include "common.h"
#include "globals.h"

using namespace std;

unExpr::unExpr(string opr, class Expr *expr) {
    this->opr = opr;
    this->body = expr;
    this->etype = exprType::Unexpr;
}

Value *unExpr::codegen(globals *currentGlobals) {
    Value *v = body->codegen(currentGlobals);
    if (body->getEtype() == exprType::location) {
        v = currentGlobals->Builder->CreateLoad(v);
    }
    if (opr == "-") {
        return currentGlobals->Builder->CreateNeg(v, "negtmp");
    } else if (opr == "!") {
        return currentGlobals->Builder->CreateNot(v, "nottmp");
    }
}
