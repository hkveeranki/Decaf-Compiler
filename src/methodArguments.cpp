//
// Created by harry7 on 7/4/18.
//

#include <vector>
#include "methodArguments.h"
#include "globals.h"

methodArguments::methodArguments() {
    this->cnt = 0;
}

std::vector<class methodArgument *> methodArguments::getArgList() {
    return arg_list;
}

void methodArguments::push_back(class methodArgument *arg) {
    arg_list.push_back(arg);
    this->cnt++;
}

Value *methodArguments::generateCode(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}
