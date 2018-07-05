//
// Created by harry7 on 7/4/18.
//


#include "returnStatement.h"
#include "globals.h"

returnStatement::returnStatement(class Expression *expr) {
    this->stype = stmtType::Return;
    this->ret = expr;
}

Value *returnStatement::generateCode(globals *currentGlobals) {
    llvm::Value *V = nullptr;
    if (ret != nullptr) {
        V = ret->generateCode(currentGlobals);
        if (ret->getEtype() == exprType::location) {
            V = currentGlobals->Builder->CreateLoad(V);
        }
        return V;
    }
    return V;
}
