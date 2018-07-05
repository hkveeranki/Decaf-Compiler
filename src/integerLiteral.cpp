//
// Created by harry7 on 7/4/18.
//

#include "integerLiteral.h"

#include "globals.h"
#include <string>


integerLiteral::integerLiteral(int value) {
    this->value = value;
    this->ltype = literalType::Int;
}

int integerLiteral::getValue() {
    return value;
}

Value *integerLiteral::generateCode(globals *currentGlobals) {
    Value *v = ConstantInt::get(currentGlobals->Context, llvm::APInt(32, value));
    return v;
}