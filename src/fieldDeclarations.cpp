/**
 * Implementation of \ref fieldDeclarations class
 */

#include "fieldDeclarations.h"

/**
 * add a given field declaration to the list of declarations
 * @param field_declaration given field declaration to be added
 */
void fieldDeclarations::push_back(class fieldDeclaration *field_declaration) {
    declaration_list.push_back(field_declaration);
}

Value *fieldDeclarations::generateCode(Constructs *compilerConstructs) {
    for (auto &i : declaration_list) {
        i->generateCode(compilerConstructs);
    }
    Value *v = ConstantInt::get(compilerConstructs->Context, APInt(32, 1));
    return v;
}