/**
 * Implementation of \ref unaryExpression class */

#include "unaryExpression.h"
#include "location.h"
using namespace std;

/**
 * Constructor to the class
 * @param opr operator in the unary expression
 * @param expr body of the expression
 */
unaryExpression::unaryExpression(string opr, class Expression *expr) {
    this->opr = std::move(opr);
    this->body = expr;
    this->etype = exprType::unExpr;
}

Value *unaryExpression::generateCode(Constructs *compilerConstructs) {
    /// Generate IR for body of the expression
    Value *v = body->generateCode(compilerConstructs);
    if (body->getEtype() == exprType::location) {
        Location *loc = static_cast<Location *>(body);
        v = compilerConstructs->Builder->CreateLoad(loc->getValueType(v), v);
    }
    /// Generate the code for operation based on the operator
    if (opr == "-") {
        return compilerConstructs->Builder->CreateNeg(v, "negtmp");
    } else if (opr == "!") {
        return compilerConstructs->Builder->CreateNot(v, "nottmp");
    }
}
