//
// Created by harry7 on 7/4/18.
//

#include "fieldDecls.h"

fieldDecls::fieldDecls() {
    this->cnt = 0;
}

void fieldDecls::push_back(class fieldDecl *var) {
    decl_list.push_back(var);
    cnt++;
}

Value *fieldDecls::codegen(globals* currentGlobals) {
    for (auto &i : decl_list) {
        i->codegen(currentGlobals);
    }
    Value *v = ConstantInt::get(currentGlobals->Context, APInt(32, 1));
    return v;
}