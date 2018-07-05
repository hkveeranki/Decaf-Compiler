//
// Created by harry7 on 7/4/18.
//

#include "stmts.h"
#include "common.h"
#include "globals.h"

Stmts::Stmts() {
    this->cnt = 0;
}

bool Stmts::has_return() {
    for (int i = 0; i < stmts.size(); i++) {
        if (stmts[i]->has_return()) {
            return true;
        }
    }
    return false;
}

Value *Stmts::codegen(globals *currentGlobals) {
    Value *v = ConstantInt::get(currentGlobals->Context, llvm::APInt(32, 1));
    for (auto &stmt : stmts) {
        v = stmt->codegen(currentGlobals);
    }
    return v;
}

void Stmts::push_back(class Stmt *stmt) {
    stmts.push_back(stmt);
    cnt++;
}
