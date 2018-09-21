/**
 * Implementation of \ref ifElseStatements class
 */

#include "ifElseStatements.h"
#include "utilities.h"

/**
 * Constructor for the class
 * @param condition condition in the if
 * @param block1 block for the if
 * @param block2 block for else part
 */
ifElseStatements::ifElseStatements(class Expression *condition, class Block *block1, class Block *block2) {
    this->stype = stmtType::NonReturn;
    this->condition = condition;
    this->if_block = block1;
    this->else_block = block2;
}

Value *ifElseStatements::generateCode(Constructs *compilerConstructs) {
    /* Generate code for the condition */
    Value *cond = condition->generateCode(compilerConstructs);
    if (cond == nullptr) {
        compilerConstructs->errors++;
        return reportError("Invalid Expression in the IF");
    }

    /* Create blocks for if, else and next part of the code */
    Function *TheFunction = compilerConstructs->Builder->GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(compilerConstructs->Context, "if", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(compilerConstructs->Context, "else");
    BasicBlock *nextBlock = BasicBlock::Create(compilerConstructs->Context, "ifcont");
    BasicBlock *otherBlock = elseBlock;
    bool ret_if = if_block->has_return(), ret_else = false;
    /// Create a conditional break and an insert point
    if (else_block == nullptr) {
        otherBlock = nextBlock;
    }
    compilerConstructs->Builder->CreateCondBr(cond, ifBlock, otherBlock);
    compilerConstructs->Builder->SetInsertPoint(ifBlock);
    /// generate the code for if block
    Value *if_val = if_block->generateCode(compilerConstructs);
    if (if_val == nullptr) {
        return nullptr;
    }
    /// Create a break for next part of the code after else block

    if (!ret_if) {
        compilerConstructs->Builder->CreateBr(nextBlock);
    }

    ifBlock = compilerConstructs->Builder->GetInsertBlock();
    /// Create insert point for else block

    Value *else_val = nullptr;

    if (else_block != nullptr) {
        /// Generate code for else block
        TheFunction->getBasicBlockList().push_back(elseBlock);
        compilerConstructs->Builder->SetInsertPoint(elseBlock);
        else_val = else_block->generateCode(compilerConstructs);
        if (else_val == nullptr) {
            return nullptr;
        }
        ret_else = else_block->has_return();
        if (!ret_else)
            compilerConstructs->Builder->CreateBr(nextBlock);
    }
    // Create a break for the next part of the code
    TheFunction->getBasicBlockList().push_back(nextBlock);
    compilerConstructs->Builder->SetInsertPoint(nextBlock);
    if (ret_else && ret_if) {
        // if both if and else block have a return statement create a dummy instruction to hold a next block
        Type *retType = compilerConstructs->Builder->GetInsertBlock()->getParent()->getReturnType();
        if (retType == Type::getVoidTy(compilerConstructs->Context))
            compilerConstructs->Builder->CreateRetVoid();
        else {
            compilerConstructs->Builder->CreateRet(ConstantInt::get(compilerConstructs->Context, APInt(32, 0)));
        }
    }
    Value *V = ConstantInt::get(compilerConstructs->Context, APInt(32, 0));
    return V;
}

/**
 * See if this block of if else statements return a value
 * @return true if the return a value false otherwise
 */
bool ifElseStatements::has_return() {
    bool status = false;
    if (if_block != nullptr) {
        status = status | if_block->has_return();
    }
    if (else_block != nullptr) {
        status = status | if_block->has_return();
    }
    return status;
}
