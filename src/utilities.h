/**
 * Utility functions needed for the compiler
 */

#ifndef DECAF_COMPILER_UTILITIES_H
#define DECAF_COMPILER_UTILITIES_H

#include <llvm/IR/Function.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include <string>
#include <iostream>
#include <llvm/IR/Value.h>
#include "constructs.h"

using namespace std;

string replace_newline(string);

llvm::Value *reportError(string);

#endif
