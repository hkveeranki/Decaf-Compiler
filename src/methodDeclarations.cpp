/**
 * Implementation of \ref methodDeclarations class
 */

#include "methodDeclarations.h"

/**
 * Add a declaration to the list
 * @param declaration method declaration to be added
 */
void methodDeclarations::push_back(class methodDeclaration *declaration) {
    decl_list.insert(decl_list.begin(), declaration);
}

Value *methodDeclarations::generateCode(Constructs *compilerConstructs) {
    Value *V = ConstantInt::get(compilerConstructs->Context, APInt(32, 0));
    for (auto &i : decl_list) {
        V = i->generateCode(compilerConstructs);
        if (V == nullptr) return V;
    }
    return V;
}