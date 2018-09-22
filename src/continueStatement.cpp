/**
 * Implementation of the \ref  continueStatement class
 */
#include "expression.h"
#include "continueStatement.h"
#include "utilities.h"

Value *continueStatement::generateCode(Constructs *compilerConstructs) {
    llvm::Value *V = llvm::ConstantInt::get(compilerConstructs->Context, llvm::APInt(32, 1));
    loopInfo *currentLoop = compilerConstructs->loops->top();
    Expression *condition = nullptr;
    string var = currentLoop->getLoopVariable();
    AllocaInst *Alloca = compilerConstructs->NamedValues[var];
    Value *step_val = ConstantInt::get(compilerConstructs->Context, APInt(32, 1));
    Value *cur = compilerConstructs->Builder->CreateLoad(Alloca, var);
    Value *next_val = compilerConstructs->Builder->CreateAdd(cur, step_val, "NextVal");
    compilerConstructs->Builder->CreateStore(next_val, Alloca);
    llvm::Value *cond = compilerConstructs->Builder->CreateICmpULE(next_val, currentLoop->getCondition(),
                                                                   "loopcondition");
    BasicBlock *loopEndBlock = compilerConstructs->Builder->GetInsertBlock();
    compilerConstructs->Builder->CreateCondBr(cond, currentLoop->getCheckBlock(), currentLoop->getAfterBlock());
    return V;
}