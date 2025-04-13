/**
 * Implementation of the \ref  breakStatement class
 */
#include "breakStatement.h"

Value *breakStatement::generateCode(Constructs *compilerConstructs) {
    loopInfo *currentLoop = compilerConstructs->loops->top();
    compilerConstructs->Builder->CreateBr(currentLoop->getAfterBlock());
    llvm::Value *V = llvm::ConstantInt::get(compilerConstructs->Context, llvm::APInt(32, 1));
    return V;
}