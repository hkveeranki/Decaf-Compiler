//
// Created by harry7 on 7/4/18.
//

#include "varDecls.h"
#include "common.h"
#include "globals.h"

varDecls::varDecls() {
    this->cnt = 0;
}

void varDecls::push_back(class varDecl *decl) {
    decl_list.push_back(decl);
    cnt++;
}

Value *varDecls::codegen(map<string, AllocaInst *> &Old_vals, globals *currentGlobals) {
    Value *v = ConstantInt::get(currentGlobals->Context, APInt(32, 1));
    for (int i = 0; i < decl_list.size(); i++) {
        v = decl_list[i]->codegen(Old_vals, currentGlobals);
    }
    return v;
}