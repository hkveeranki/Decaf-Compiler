//
// Created by harry7 on 7/4/18.
//

#include <llvm/IR/Constants.h>
#include <llvm/IR/LLVMContext.h>

#include "common.h"
#include "var.h"

LLVMContext Context;

Var::Var(string declType, string name, unsigned int length) {
    this->declType = std::move(declType);
    this->name = std::move(name);
    this->length = length;
}

Var::Var(string declType, string name) {
    this->declType = std::move(declType);
    this->name = std::move(name);
}

bool Var::isArray() {
    return (declType == "Array");
}

void Var::setDataType(string datatype) {
    /* Sets the data type for the variable */
    this->dataType = std::move(datatype);
}

string Var::getName() {
    return name;
}


Value *Var::codegen(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}
