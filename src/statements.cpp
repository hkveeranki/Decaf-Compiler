/**
 * Implementation of \ref Statements class
 */
#include "statements.h"

/**
 * Tells whether this set of statements return anything
 * @return true if the return something false otherwise
 */
bool Statements::has_return() {
    for (int i = 0; i < statements_list.size(); i++) {
        if (statements_list[i]->has_return()) {
            return true;
        }
    }
    return false;
}

Value *Statements::generateCode(Constructs *compilerConstructs) {
    Value *v = ConstantInt::get(compilerConstructs->Context, llvm::APInt(32, 1));
    for (auto &stmt : statements_list) {
        v = stmt->generateCode(compilerConstructs);
    }
    return v;
}

/**
 * Add a given statement to the list of statements
 * @param statement statement to be added
 */
void Statements::push_back(class Statement *statement) {
    statements_list.push_back(statement);
}
