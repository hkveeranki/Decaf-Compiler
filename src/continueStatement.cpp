/**
 * Implementation of the \ref  continueStatement class
 */
#include "continueStatement.h"

Value *continueStatement::generateCode(Constructs *compilerConstructs) {
    llvm::Value *V = llvm::ConstantInt::get(compilerConstructs->Context, llvm::APInt(32, 1));
    return V;
}