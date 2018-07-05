//
// Created by harry7 on 7/4/18.
//

#include "intLiteral.h"
#include "common.h"
#include "globals.h"
#include <string>


intLiteral::intLiteral(int value) {
    this->value = value;
    this->ltype = literalType::Int;
}

int intLiteral::getValue() {
    return value;
}

Value *intLiteral::codegen(globals *currentGlobals) {
    Value *v = ConstantInt::get(currentGlobals->Context, llvm::APInt(32, value));
    return v;
}