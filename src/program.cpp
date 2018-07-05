//
// Created by harry7 on 7/4/18.
//

#include "program.h"


Program::Program(string name, class fieldDeclarations *decls, class methodDeclarations *methods) {
    this->methods = methods;
    this->name = name;
    this->fields = decls;
    this->currentGlobals = new globals();
}

Value *Program::generateCode() {
    Value *V;
    int errors = 0;
    V = fields->generateCode(this->currentGlobals);
    V = methods->generateCode(this->currentGlobals);
    return V;
}

void Program::generateCodeDump() {
    cerr << "Generating LLVM IR Code\n";
    this->currentGlobals->TheModule->print(llvm::outs(), nullptr);
}