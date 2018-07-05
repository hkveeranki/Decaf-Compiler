//
// Created by harry7 on 7/4/18.
//

#include "parameters.h"
#include "globals.h"
#include <vector>

Parameters::Parameters() {
    this->cnt = 0;
}

void Parameters::push_back(class Expression *expr) {
    expr_list.push_back(expr);
    cnt++;
}

Value *Parameters::generateCode(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}

std::vector<class Expression *> Parameters::getExprList() {
    return expr_list;
}