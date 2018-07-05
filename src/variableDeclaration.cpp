//
// Created by harry7 on 7/4/18.
//

#include <utility>
#include <string>
#include <vector>

#include "variableDeclaration.h"

variableDeclaration::variableDeclaration(std::string data_type, class stringList *list) {
    std::vector<std::string> tmp = list->getList();
    this->type = std::move(data_type);
    this->cnt = 0;
    for (int i = 0; i < tmp.size(); i++) {
        this->push_back(tmp[i]);
    }
}

void variableDeclaration::push_back(std::string var) {
    var_list.push_back(var);
    this->cnt++;
}

Value *variableDeclaration::generateCode(std::map<std::string, llvm::AllocaInst *> &Old_vals, globals *currentGlobals) {
    /* Get the function in which this belongs */
    Function *TheFunction = currentGlobals->Builder->GetInsertBlock()->getParent();
    for (int i = 0; i < var_list.size(); i++) {
        std::string var = var_list[i];
        llvm::Value *initval = nullptr;
        llvm::AllocaInst *Alloca = nullptr;
        if (type == "int") {
            initval = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
            Alloca = currentGlobals->CreateEntryBlockAlloca(TheFunction, var, "int");
        } else if (type == "boolean") {
            initval = ConstantInt::get(currentGlobals->Context, APInt(1, 0));
            Alloca = currentGlobals->CreateEntryBlockAlloca(TheFunction, var, "boolean");
        }
        currentGlobals->Builder->CreateStore(initval, Alloca);
        /* Store the old value to old_vals and new value to named values */
        Old_vals[var] = currentGlobals->NamedValues[var];
        currentGlobals->NamedValues[var] = Alloca;
    }
    Value *v = ConstantInt::get(currentGlobals->Context, APInt(32, 1));
    return v;
}
