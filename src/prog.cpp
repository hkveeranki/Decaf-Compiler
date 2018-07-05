//
// Created by harry7 on 7/4/18.
//

#include "prog.h"
#include "common.h"

Prog::Prog(string name, class fieldDecls *decls, class methodDecls *methods) {
    this->methods = methods;
    this->name = name;
    this->fields = decls;
    this->currentGlobals = new globals();
}

Value *Prog::codegen() {
    Value *V;
    int errors = 0;
    V = fields->codegen(this->currentGlobals);
    V = methods->codegen(this->currentGlobals);
    return V;
}

void Prog::generateCode() {
    cerr << "Generating LLVM IR Code\n";
    this->currentGlobals->TheModule->print(llvm::outs(), nullptr);
}