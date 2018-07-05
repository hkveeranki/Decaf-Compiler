//
// Created by harry7 on 7/4/18.
//

#include <string>
#include "variableDeclarations.h"
#include "globals.h"

variableDeclarations::variableDeclarations() {
    this->cnt = 0;
}

void variableDeclarations::push_back(class variableDeclaration *decl) {
    decl_list.push_back(decl);
    cnt++;
}

Value *variableDeclarations::generateCode(std::map<std::string, AllocaInst *> &Old_vals, globals *currentGlobals) {
    Value *v = ConstantInt::get(currentGlobals->Context, APInt(32, 1));
    for (int i = 0; i < decl_list.size(); i++) {
        v = decl_list[i]->generateCode(Old_vals, currentGlobals);
    }
    return v;
}