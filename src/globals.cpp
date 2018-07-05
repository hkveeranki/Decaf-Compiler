//
// Created by harry7 on 7/5/18.
//

#include "globals.h"

globals::globals() {
    this->Builder = new IRBuilder<>(Context);
    errors = 0;
    this->TheModule = new Module("Decaf compiler jit", Context);
}

AllocaInst *globals::CreateEntryBlockAlloca(Function *TheFunction, std::string VarName, std::string type) {

    /* Allocates memory for local variables  on the stack of the function */
    /* Get the builder for current context */
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *Alloca = nullptr;
    if (type == "int") {
        Alloca = TmpB.CreateAlloca(Type::getInt32Ty(this->Context), 0, VarName);
    } else if (type == "boolean") {
        Alloca = TmpB.CreateAlloca(Type::getInt1Ty(this->Context), 0, VarName);
    }
    return Alloca;
}
