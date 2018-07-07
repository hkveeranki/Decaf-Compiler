/**
 * Implementation of the \ref  boolLiteral class */
#include "boolLiteral.h"
#include "utilities.h"

/**
 * Constructor for the class. Store its value as a string
 * @param value string containing the value of the literal. Can be "true" or "false"
 */
boolLiteral::boolLiteral(std::string value) {
    this->value = std::move(value);
    this->ltype = literalType::Bool;
}


Value *boolLiteral::generateCode(Constructs *compilerConstructs) {
    bool val;
    if (value == "true") val = true;
    else if (value == "false") val = false;
    else {
        compilerConstructs->errors++;
        return reportError("Invalid Boolean Literal " + value);
    }
    Value *v = ConstantInt::get(compilerConstructs->Context, llvm::APInt(1, val));
    return v;
}
