//
// Created by harry7 on 7/4/18.
//

#include "ifElseStatements.h"
#include "utilities.h"


ifElseStatements::ifElseStatements(class Expression *cond, class Block *block1, class Block *block2) {
    this->stype = stmtType::NonReturn;
    this->condition = cond;
    this->if_block = block1;
    this->else_block = block2;
}

Value *ifElseStatements::generateCode(globals *currentGlobals) {
    Value *cond = condition->generateCode(currentGlobals);
    if (cond == 0) {
        currentGlobals->errors++;
        return reportError("Invalid Expression in the IF");
    }
    Function *TheFunction = currentGlobals->Builder->GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(currentGlobals->Context, "if", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(currentGlobals->Context, "else");
    BasicBlock *nextBlock = BasicBlock::Create(currentGlobals->Context, "ifcont");
    currentGlobals->Builder->CreateCondBr(cond, ifBlock, elseBlock);

    currentGlobals->Builder->SetInsertPoint(ifBlock);

    Value *ifval = if_block->generateCode(currentGlobals);
    if (ifval == nullptr) {
        return 0;
    }

    currentGlobals->Builder->CreateBr(nextBlock);
    ifBlock = currentGlobals->Builder->GetInsertBlock();

    TheFunction->getBasicBlockList().push_back(elseBlock);
    currentGlobals->Builder->SetInsertPoint(elseBlock);
    Value *elseval;
    if (else_block != nullptr) {
        elseval = else_block->generateCode(currentGlobals);
        if (elseval == 0) {
            return 0;
        }
    }
    currentGlobals->Builder->CreateBr(nextBlock);
    elseBlock = currentGlobals->Builder->GetInsertBlock();
    TheFunction->getBasicBlockList().push_back(nextBlock);
    currentGlobals->Builder->SetInsertPoint(nextBlock);

    bool phi_if = false, phi_else = false;
    if (if_block->has_return()) {
        phi_if = true;
    }
    if (else_block != nullptr && else_block->has_return()) {
        phi_else = true;
    }
    if (phi_if || phi_else) {
        PHINode *PN = currentGlobals->Builder->CreatePHI(Type::getInt32Ty(currentGlobals->Context), 2, "iftmp");
        if (phi_if)
            PN->addIncoming(ifval, ifBlock);
        if (phi_else) {
            PN->addIncoming(elseval, elseBlock);
        }
        return PN;
    }

    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    return V;
}