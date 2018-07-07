/**
 * Implementation of the \ref  Program class
 */

#include "program.h"

/**
 * Constructor for the class
 * @param name name of the decaf class
 * @param fields field Declarations of the class
 * @param methods method declarations of the class
 */
Program::Program(string name, class fieldDeclarations *fields, class methodDeclarations *methods) {
    this->methods = methods;
    this->name = std::move(name);
    this->fields = fields;
    this->compilerConstructs = new Constructs();
}

/**
 * Generate the IR for the program
 */
Value *Program::generateCode() {
    Value *V;
    // Generate code for field Declarations
    V = fields->generateCode(this->compilerConstructs);
    if (V == nullptr) {
        reportError("Invalid field Declarations");
        return nullptr;
    }
    //Generate the code for method Declarations
    V = methods->generateCode(this->compilerConstructs);
    if (V == nullptr) {
        reportError("Invalid method Declarations");
        return nullptr;
    }
    return V;
}

/**
 * Dump the IR generated onto stdout
 */
void Program::generateCodeDump() {
    cerr << "Generating LLVM IR Code\n";
    this->compilerConstructs->TheModule->print(llvm::outs(), nullptr);
}