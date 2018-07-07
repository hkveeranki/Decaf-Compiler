/**
 * Implementation of \ref enclosedExpression class */
#include "enclosedExpression.h"

/**
 * Constructor for the class
 * @param expr expression which is enclosed within the braces
 */
enclosedExpression::enclosedExpression(class Expression *expr) {
    this->expr = expr;
    this->etype = exprType::enclExpr;
}

Value *enclosedExpression::generateCode(Constructs *compilerConstructs) {
    return expr->generateCode(compilerConstructs);
}
