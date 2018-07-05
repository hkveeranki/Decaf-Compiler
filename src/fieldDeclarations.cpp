//
// Created by harry7 on 7/4/18.
//

#include "fieldDeclarations.h"

fieldDeclarations::fieldDeclarations() {
    this->cnt = 0;
}

void fieldDeclarations::push_back(class fieldDeclaration *var) {
    decl_list.push_back(var);
    cnt++;
}

Value *fieldDeclarations::generateCode(globals* currentGlobals) {
    for (auto &i : decl_list) {
        i->generateCode(currentGlobals);
    }
    Value *v = ConstantInt::get(currentGlobals->Context, APInt(32, 1));
    return v;
}