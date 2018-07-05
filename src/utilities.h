//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_UTILITIES_H
#define DECAF_COMPILER_UTILITIES_H

#include <llvm/IR/Function.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include <string>
#include "globals.h"

using namespace std;

std::string replace_newline(std::string);

AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, string VarName, std::string type, globals* currentGlobals);
#endif //DECAF_COMPILER_UTILITIES_H
