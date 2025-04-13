/**
 * Implementation of \ref forStatement class
 */
#include <utility>
#include "forStatement.h"
#include "utilities.h"
#include "location.h"

/**
 * Constructor for the class
 * @param loop_variable variable iterated in the loop
 * @param init initial value for the loop variable
 * @param condition condition for the loop variable to break
 * @param block body of the for loop
 */
forStatement::forStatement(string loop_variable, class Expression *init, class Expression *condition,
                           class Block *block) {
    this->var = std::move(loop_variable);
    this->init = init;
    this->condition = condition;
    this->body = block;
}

Value *forStatement::generateCode(Constructs *compilerConstructs) {

    Value *start = init->generateCode(compilerConstructs);
    if (start == nullptr) {
        return nullptr;
    }
    if (init->getEtype() == exprType::location) {
        Location *loc = static_cast<Location *>(init);
        start = compilerConstructs->Builder->CreateLoad(loc->getValueType(start), start);
    }
    /* Get the parent method of this for loop */
    Function *TheFunction = compilerConstructs->Builder->GetInsertBlock()->getParent();
    /* Create memory for the loop variable */
    llvm::AllocaInst *Alloca = compilerConstructs->CreateEntryBlockAlloca(TheFunction, var, string("int"));
    compilerConstructs->Builder->CreateStore(start, Alloca);

    Value *step_val = ConstantInt::get(compilerConstructs->Context, APInt(32, 1));
    BasicBlock *pre_header_basic_block = compilerConstructs->Builder->GetInsertBlock();
    BasicBlock *loop_body = BasicBlock::Create(compilerConstructs->Context, "loop", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(compilerConstructs->Context, "afterloop", TheFunction);
    compilerConstructs->Builder->CreateBr(loop_body);
    compilerConstructs->Builder->SetInsertPoint(loop_body);

    PHINode *Variable = compilerConstructs->Builder->CreatePHI(Type::getInt32Ty(compilerConstructs->Context), 2, var);
    Variable->addIncoming(start, pre_header_basic_block);
    /* Store the old value */
    Value *cond = condition->generateCode(compilerConstructs);
    if (cond == nullptr) {
        compilerConstructs->errors++;
        return reportError("Invalid Condition");
    }

    // Check if condition is a location
    if (condition->getEtype() == exprType::location) {
        Location *loc = static_cast<Location* >(condition);
        cond = compilerConstructs->Builder->CreateLoad(loc->getValueType(cond), cond);
    }
    compilerConstructs->loops->push(new loopInfo(afterBB, loop_body, cond, var, Variable));
    llvm::AllocaInst *OldVal = compilerConstructs->NamedValues[var];
    compilerConstructs->NamedValues[var] = Alloca;
    /* Generate the code for the body */
    if (body->generateCode(compilerConstructs) == nullptr) {
        return nullptr;
    }

    Value *cur = compilerConstructs->Builder->CreateLoad(Alloca->getAllocatedType(), Alloca, var);
    Value *next_val = compilerConstructs->Builder->CreateAdd(cur, step_val, "NextVal");
    compilerConstructs->Builder->CreateStore(next_val, Alloca);
    cond = compilerConstructs->Builder->CreateICmpSLT(next_val, cond, "loopcondition");
    BasicBlock *loopEndBlock = compilerConstructs->Builder->GetInsertBlock();
    compilerConstructs->Builder->CreateCondBr(cond, loop_body, afterBB);
    compilerConstructs->Builder->SetInsertPoint(afterBB);
    Variable->addIncoming(next_val, loopEndBlock);

    if (OldVal) {
        compilerConstructs->NamedValues[var] = OldVal;
    } else {
        compilerConstructs->NamedValues.erase(var);
    }
    llvm::Value *V = ConstantInt::get(compilerConstructs->Context, APInt(32, 1));
    return V;
}
