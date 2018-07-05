//
// Created by harry7 on 7/4/18.
//

#include <llvm/IR/Constants.h>
#include <llvm/IR/LLVMContext.h>

#include "variable.h"

LLVMContext Context;

Variable::Variable(string declType, string name, unsigned int length) {
    this->declType = std::move(declType);
    this->name = std::move(name);
    this->length = length;
}

Variable::Variable(string declType, string name) {
    this->declType = std::move(declType);
    this->name = std::move(name);
}

bool Variable::isArray() {
    return (declType == "Array");
}

void Variable::setDataType(string datatype) {
    /* Sets the data type for the variable */
    this->dataType = std::move(datatype);
}

string Variable::getName() {
    return name;
}


Value *Variable::generateCode(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}
