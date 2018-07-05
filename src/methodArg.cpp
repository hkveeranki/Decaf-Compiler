//
// Created by harry7 on 7/4/18.
//

#include <utility>
#include "common.h"
#include "methodArg.h"
#include "globals.h"

methodArg::methodArg(string type, string name) {
    this->type = std::move(type);
    this->name = std::move(name);
}


string methodArg::getName() {
    return name;
}

string methodArg::getType() {
    return type;
}

Value *methodArg::codegen(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}