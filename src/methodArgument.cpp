//
// Created by harry7 on 7/4/18.
//

#include <utility>
#include <string>
#include "methodArgument.h"
#include "globals.h"

methodArgument::methodArgument(std::string type, std::string name) {
    this->type = std::move(type);
    this->name = std::move(name);
}


std::string methodArgument::getName() {
    return name;
}

std::string methodArgument::getType() {
    return type;
}

Value *methodArgument::generateCode(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}