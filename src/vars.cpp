//
// Created by harry7 on 7/4/18.
//

#include <llvm/IR/Constants.h>
#include "common.h"
#include "vars.h"
#include "var.h"

vector<class Var *> Vars::getVarsList() {
    return vars_list;
}

void Vars::push_back(class Var *var) {
    vars_list.push_back(var);
    cnt++;
}

Value *Vars::codegen(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}