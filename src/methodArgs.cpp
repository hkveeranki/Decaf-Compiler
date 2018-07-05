//
// Created by harry7 on 7/4/18.
//

#include "methodArgs.h"
#include "common.h"
#include "globals.h"

methodArgs::methodArgs() {
    this->cnt = 0;
}

vector<class methodArg *> methodArgs::getArgList() {
    return arg_list;
}

void methodArgs::push_back(class methodArg *arg) {
    arg_list.push_back(arg);
    this->cnt++;
}

Value *methodArgs::codegen(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}
