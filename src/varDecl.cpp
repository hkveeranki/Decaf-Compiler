//
// Created by harry7 on 7/4/18.
//

#include <utility>

#include "common.h"
#include "varDecl.h"
#include "utilities.h"

varDecl::varDecl(string data_type, class stringList *list) {
    vector<string> tmp = list->getList();
    this->type = std::move(data_type);
    this->cnt = 0;
    for (int i = 0; i < tmp.size(); i++) {
        this->push_back(tmp[i]);
    }
}

void varDecl::push_back(string var) {
    var_list.push_back(var);
    this->cnt++;
}

Value *varDecl::codegen(map<string, llvm::AllocaInst *> &Old_vals, globals *currentGlobals) {
    Function *TheFunction = currentGlobals->Builder->GetInsertBlock()->getParent(); /* Get the function in which this belongs */
    for (int i = 0; i < var_list.size(); i++) {
        string var = var_list[i];
        llvm::Value *initval = nullptr;
        llvm::AllocaInst *Alloca = nullptr;
        if (type == "int") {
            initval = ConstantInt::get(currentGlobals->Context, APInt(32, 0));
            Alloca = CreateEntryBlockAlloca(TheFunction, var, "int", currentGlobals);
        } else if (type == "boolean") {
            initval = ConstantInt::get(currentGlobals->Context, APInt(1, 0));
            Alloca = CreateEntryBlockAlloca(TheFunction, var, "boolean", currentGlobals);
        }
        currentGlobals->Builder->CreateStore(initval, Alloca);
        /* Store the old value to old_vals and new value to named values */
        Old_vals[var] = currentGlobals->NamedValues[var];
        currentGlobals->NamedValues[var] = Alloca;
    }
    Value *v = ConstantInt::get(currentGlobals->Context, APInt(32, 1));
    return v;
}
