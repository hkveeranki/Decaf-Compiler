/**
 * Implementation of the \ref  calloutArgument class
 */

#include "calloutArgument.h"
#include "stringLiteral.h"
#include "utilities.h"

/**
 * Constructor for the class when expression argument is given to callout
 * @param arg expression which is given as an argument
 */
calloutArgument::calloutArgument(class Expression *arg) {
    this->expr = arg;
}

/**
 * Constructor for the class when it should deal string arguments
 * @param literal string that is given as an argument
 */
calloutArgument::calloutArgument(std::string literal) {
    class stringLiteral *tmp = new stringLiteral(std::move(literal));
    this->expr = tmp;
}


Value *calloutArgument::generateCode(Constructs *compilerConstructs) {
    if (expr == nullptr) {
        compilerConstructs->errors++;
        return reportError("Invalid Callout Arg");
    }
    Value *v = expr->generateCode(compilerConstructs);
    if (expr->getEtype() == exprType::location) {
        v = compilerConstructs->Builder->CreateLoad(v);
    }
    return v;
}