//
// Created by harry7 on 7/4/18.
//

#include "params.h"
#include "common.h"
#include "globals.h"

Params::Params() {
    this->cnt = 0;
}

void Params::push_back(class Expr *expr) {
    expr_list.push_back(expr);
    cnt++;
}

Value *Params::codegen(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}

vector<class Expr *> Params::getExprList() {
    return expr_list;
}