/**
 * Implementation of \ref variableDeclarations class
 */
#include <string>
#include "variableDeclarations.h"

using namespace std;

/**
 * add a declaration to the list of declarations
 * @param decl declaration to be added
 */
void variableDeclarations::push_back(class variableDeclaration *decl) {
    decl_list.push_back(decl);
}

Value *variableDeclarations::generateCode(map<string, AllocaInst *> &oldValues, Constructs *compilerConstructs) {

    Value *v = ConstantInt::get(compilerConstructs->Context, APInt(32, 1));
    for (auto &decl : decl_list) {
        /// Generate the code for each declaration
        v = decl->generateCode(oldValues, compilerConstructs);
        if (v == nullptr) {
            return v;
        }
    }
    return v;
}