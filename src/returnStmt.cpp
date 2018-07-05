//
// Created by harry7 on 7/4/18.
//

#include "common.h"
#include "returnStmt.h"
#include "globals.h"

returnStmt::returnStmt(class Expr *expr) {
    this->stype = stmtType::Return;
    this->ret = expr;
}

Value *returnStmt::codegen(globals *currentGlobals) {
    llvm::Value *V = nullptr;
    if (ret != nullptr) {
        V = ret->codegen(currentGlobals);
        if (ret->getEtype() == exprType::location) {
            V = currentGlobals->Builder->CreateLoad(V);
        }
        return V;
    }
    return V;
}
