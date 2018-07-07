//
// Created by harry7 on 7/4/18.
//

#include <utility>
#include <string>
#include <vector>

#include "variableDeclaration.h"

using namespace std;

/**
 * Constructor of the class
 * @param data_type data type of the declaration
 * @param list list of variables in the declaration
 */
variableDeclaration::variableDeclaration(string data_type, class stringList *list) {
    vector<string> tmp = list->getList();
    this->type = move(data_type);
    for (const auto &i : tmp) {
        this->push_back(i);
    }
}

/**
 * Add a variable to the list of variables in the declaration
 * @param var variable name to be added
 */
void variableDeclaration::push_back(string var) {
    var_list.push_back(var);
}

Value *variableDeclaration::generateCode(map<string, llvm::AllocaInst *> &Old_vals, Constructs *compilerConstructs) {
    /* Get the function to which this declaration belongs */
    llvm::Function *TheFunction = compilerConstructs->Builder->GetInsertBlock()->getParent();
    for (const auto &var : var_list) {
        llvm::Value *initval = nullptr;
        llvm::AllocaInst *Alloca = nullptr;
        if (type == "int") {
            initval = ConstantInt::get(compilerConstructs->Context, APInt(32, 0));
            Alloca = compilerConstructs->CreateEntryBlockAlloca(TheFunction, var, "int");
        } else if (type == "boolean") {
            initval = ConstantInt::get(compilerConstructs->Context, APInt(1, 0));
            Alloca = compilerConstructs->CreateEntryBlockAlloca(TheFunction, var, "boolean");
        }
        compilerConstructs->Builder->CreateStore(initval, Alloca);
        /* Store the old value to old_vals and new value to named values */
        Old_vals[var] = compilerConstructs->NamedValues[var];
        compilerConstructs->NamedValues[var] = Alloca;
    }
    Value *v = ConstantInt::get(compilerConstructs->Context, APInt(32, 1));
    return v;
}
