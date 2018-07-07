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
    /// Create a conditional break and an insert point
    compilerConstructs->Builder->CreateCondBr(cond, ifBlock, elseBlock);
    compilerConstructs->Builder->SetInsertPoint(ifBlock);
    /// generate the code for if block
    Value *if_val = if_block->generateCode(compilerConstructs);
    if (if_val == nullptr) {
        return nullptr;
    }
    /// Create a break for next part of the code after else block
    compilerConstructs->Builder->CreateBr(nextBlock);
    ifBlock = compilerConstructs->Builder->GetInsertBlock();

    /// Create insert point for else block
    TheFunction->getBasicBlockList().push_back(elseBlock);
    compilerConstructs->Builder->SetInsertPoint(elseBlock);
    Value *else_val = nullptr;

    if (else_block != nullptr) {
        /// Generate code for else block
        else_val = else_block->generateCode(compilerConstructs);
        if (else_val == nullptr) {
            return nullptr;
        }
    }
    // Create a break for the next part of the code
    compilerConstructs->Builder->CreateBr(nextBlock);
    elseBlock = compilerConstructs->Builder->GetInsertBlock();
    TheFunction->getBasicBlockList().push_back(nextBlock);
    compilerConstructs->Builder->SetInsertPoint(nextBlock);

    /// Create phi nodes for if and else blocks if they have return value
    bool phi_if = false, phi_else = false;
    if (if_block->has_return()) {
        phi_if = true;
    }
    if (else_block != nullptr && else_block->has_return()) {
        phi_else = true;
    }
    if (phi_if || phi_else) {
        PHINode *PN = compilerConstructs->Builder->CreatePHI(Type::getInt32Ty(compilerConstructs->Context), 2, "iftmp");
        if (phi_if)
            PN->addIncoming(if_val, ifBlock);
        if (phi_else) {
            PN->addIncoming(else_val, elseBlock);
        }
        return PN;
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
