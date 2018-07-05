//
// Created by harry7 on 7/4/18.
//

#include <llvm/IR/Constants.h>

#include "variables.h"
#include "variable.h"

vector<class Variable *> Variables::getVarsList() {
    return vars_list;
}

void Variables::push_back(class Variable *var) {
    vars_list.push_back(var);
    cnt++;
}

Value *Variables::generateCode(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}