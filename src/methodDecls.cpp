//
// Created by harry7 on 7/4/18.
//

#include "methodDecls.h"

methodDecls::methodDecls() {
    this->cnt = 0;
}

void methodDecls::push_back(class methodDecl *decl) {
    decl_list.push_back(decl);
    cnt++;
}

Value *methodDecls::codegen(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    for (int i = 0; i < decl_list.size(); i++) {
        V = decl_list[i]->codegen(currentGlobals);
    }
    return V;
}