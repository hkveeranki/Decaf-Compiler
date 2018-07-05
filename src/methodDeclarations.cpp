//
// Created by harry7 on 7/4/18.
//

#include "methodDeclarations.h"

methodDeclarations::methodDeclarations() {
    this->cnt = 0;
}

void methodDeclarations::push_back(class methodDeclaration *decl) {
    decl_list.push_back(decl);
    cnt++;
}

Value *methodDeclarations::generateCode(globals *currentGlobals) {
    Value *V = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
    for (int i = 0; i < decl_list.size(); i++) {
        V = decl_list[i]->generateCode(currentGlobals);
    }
    return V;
}