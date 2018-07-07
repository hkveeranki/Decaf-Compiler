/**
 * Implementation of \ref stringLiteral class
 */

#include "stringLiteral.h"
#include "utilities.h"

/**
 * Constructor of the class
 * @param val value of the string literal
 */
stringLiteral::stringLiteral(std::string val) {
    val = val.substr(1, val.length() - 2);
    val = replace_newline(val);
    this->value = val;
    this->ltype = literalType::String;
}

Value *stringLiteral::generateCode(Constructs *compilerConstructs) {
    return compilerConstructs->Builder->CreateGlobalStringPtr(value);
}