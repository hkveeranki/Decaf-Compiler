//
// Created by harry7 on 7/5/18.
//

#ifndef DECAF_COMPILER_GLOBALS_H
#define DECAF_COMPILER_GLOBALS_H

#include <map>
#include <string>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/IRBuilder.h>

using namespace llvm;

class globals {
public:
    LLVMContext Context;
    Module *TheModule;
    IRBuilder<>* Builder;
    std::map<std::string, llvm::AllocaInst *> NamedValues;
    FunctionPassManager *TheFPM;
    int errors;
    globals();
};


#endif //DECAF_COMPILER_GLOBALS_H
