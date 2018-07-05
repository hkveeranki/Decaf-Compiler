//
// Created by harry7 on 7/4/18.
//

#include <utility>
#include "forStmt.h"
#include "common.h"
#include "utilities.h"

forStmt::forStmt(string loc, class Expr *init, class Expr *cond, class Block *block) {
    this->stype = stmtType::NonReturn;
    this->var = std::move(loc);
    this->init = init;
    this->condition = cond;
    this->body = block;
}

Value *forStmt::codegen(globals *currentGlobals) {
    Value *start = init->codegen(currentGlobals);
    if (start == 0) {
        return 0;
    }
    Function *TheFunction = currentGlobals->Builder->GetInsertBlock()->getParent();
    llvm::AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, var, string("int"), currentGlobals);
    currentGlobals->Builder->CreateStore(start, Alloca);
    Value *step_val = ConstantInt::get(currentGlobals->Context, APInt(32, 1));
    BasicBlock *preheaderBB = currentGlobals->Builder->GetInsertBlock();
    BasicBlock *loop_body = BasicBlock::Create(currentGlobals->Context, "loop", TheFunction);
    currentGlobals->Builder->CreateBr(loop_body);
    currentGlobals->Builder->SetInsertPoint(loop_body);

    PHINode *Variable = currentGlobals->Builder->CreatePHI(Type::getInt32Ty(currentGlobals->Context), 2, var);
    Variable->addIncoming(start, preheaderBB);
    /* Store the old value */
    llvm::AllocaInst *OldVal = currentGlobals->NamedValues[var];
    currentGlobals->NamedValues[var] = Alloca;

    if (body->codegen(currentGlobals) == nullptr) {
        return 0;
    }

    Value *cur = currentGlobals->Builder->CreateLoad(Alloca, var);
    Value *nextval = currentGlobals->Builder->CreateAdd(cur, step_val, "NextVal");
    currentGlobals->Builder->CreateStore(nextval, Alloca);

    Value *cond = condition->codegen(currentGlobals);
    if (cond == 0) {
        currentGlobals->errors++;
        return reportError::ErrorV("Invalid Condition");
    }

    cond = currentGlobals->Builder->CreateICmpULE(nextval, cond, "loopcondition");
    BasicBlock *loopEndBlock = currentGlobals->Builder->GetInsertBlock();
    BasicBlock *afterBB = BasicBlock::Create(currentGlobals->Context, "afterloop", TheFunction);
    currentGlobals->Builder->CreateCondBr(cond, loop_body, afterBB);

    currentGlobals->Builder->SetInsertPoint(afterBB);
    Variable->addIncoming(nextval, loopEndBlock);

    if (OldVal) {
        currentGlobals->NamedValues[var] = OldVal;
    } else {
        currentGlobals->NamedValues.erase(var);
    }
    llvm::Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 1));
    return V;
}
