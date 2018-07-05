//
// Created by harry7 on 7/4/18.
//

#include "calloutArgs.h"
#include "common.h"
#include "globals.h"


calloutArgs::calloutArgs() {
    this->cnt = 0;
}

void calloutArgs::push_back(class calloutArg *arg) {
    args_list.push_back(arg);
    cnt++;
}

std::vector<class calloutArg *> calloutArgs::getArgsList() {
    return args_list;
}

Value *calloutArgs::codegen(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}