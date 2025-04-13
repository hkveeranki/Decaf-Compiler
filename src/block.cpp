/**
 * Implementation  for the block class
 */

#include "block.h"

#include "statements.h"
#include "variableDeclarations.h"

/**
 * Default constructor
 * @param variable_declarations variable declarations present in the block
 * @param statements list of statements present in the block
 */
Block::Block(class variableDeclarations *variable_declarations, class Statements *statements) {
    this->declarations_list = variable_declarations;
    this->statements_list = statements;
}

/**
 * Tells whether this block returns a value
 * @return True if block returns a value False otherwise
 */
bool Block::has_return() {
    return statements_list->has_return();
}

bool Block::has_break() {
    return statements_list->has_break();
}
bool Block::has_continue() {
    return statements_list->has_continue();
}

Value *Block::generateCode(Constructs *compilerConstructs) {
    Value *V;
    std::map<std::string, llvm::AllocaInst *> Old_vals;
    V = declarations_list->generateCode(Old_vals, compilerConstructs);
    if (V == nullptr) {
        return V;
    }
    V = statements_list->generateCode(compilerConstructs);
    /* Adjust the values back to old values */
    for (auto it = Old_vals.begin(); it != Old_vals.end(); it++) {
        compilerConstructs->NamedValues[it->first] = Old_vals[it->first];
    }
    return V;
}
