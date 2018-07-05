//
// Created by harry7 on 7/4/18.
//

#include "calloutArguments.h"

#include "globals.h"


calloutArguments::calloutArguments() {
    this->cnt = 0;
}

void calloutArguments::push_back(class calloutArgument *arg) {
    args_list.push_back(arg);
    cnt++;
}

std::vector<class calloutArgument *> calloutArguments::getArgsList() {
    return args_list;
}

Value *calloutArguments::generateCode(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}