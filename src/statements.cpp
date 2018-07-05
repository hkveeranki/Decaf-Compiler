//
// Created by harry7 on 7/4/18.
//

#include "statements.h"

#include "globals.h"

Statements::Statements() {
    this->cnt = 0;
}

bool Statements::has_return() {
    for (int i = 0; i < stmts.size(); i++) {
        if (stmts[i]->has_return()) {
            return true;
        }
    }
    return false;
}

Value *Statements::generateCode(globals *currentGlobals) {
    Value *v = ConstantInt::get(currentGlobals->Context, llvm::APInt(32, 1));
    for (auto &stmt : stmts) {
        v = stmt->generateCode(currentGlobals);
    }
    return v;
}

void Statements::push_back(class Statement *stmt) {
    stmts.push_back(stmt);
    cnt++;
}
