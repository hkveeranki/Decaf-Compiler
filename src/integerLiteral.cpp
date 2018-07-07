/**
 * Implementation of \\ref  integerLiteral class */

#include "integerLiteral.h"

/**
 * Constructor for the class
 * @param value value of the integer literal
 */
integerLiteral::integerLiteral(int value) {
    this->value = value;
    this->ltype = literalType::Int;
}

/**
 * Return the value of integer literal
 * @return value of the literal
 */
int integerLiteral::getValue() {
    return value;
}

Value *integerLiteral::generateCode(Constructs *compilerConstructs) {
    Value *v = ConstantInt::get(compilerConstructs->Context, llvm::APInt(32, static_cast<uint64_t>(value)));
    return v;
}