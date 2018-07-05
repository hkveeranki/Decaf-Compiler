//
// Created by harry7 on 7/4/18.
//

#include "continueStatement.h"

#include "globals.h"

Value *continueStatement::generateCode(globals *currentGlobals) {
    llvm::Value *V = llvm::ConstantInt::get(currentGlobals->Context, llvm::APInt(32, 1));
    return V;
}