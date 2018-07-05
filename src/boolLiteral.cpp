//
// Created by harry7 on 7/4/18.
//

#include "boolLiteral.h"
#include "common.h"
#include "globals.h"
#include <utility>

boolLiteral::boolLiteral(string value) {
    this->value = std::move(value);
    this->ltype = literalType::Bool;
}


Value *boolLiteral::codegen(globals *currentGlobals) {
    bool val;
    if (value == "true") val = true;
    else if (value == "false") val = false;
    else {
        currentGlobals->errors++;
        return reportError::ErrorV("Invalid Boolean Literal " + value);
    }
    Value *v = ConstantInt::get(currentGlobals->Context, llvm::APInt(1, val));
    return v;
}
