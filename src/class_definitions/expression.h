/**
 * Abstract class to define behaviour of an expression in decaf
 */

#ifndef DECAF_COMPILER_EXPR_H
#define DECAF_COMPILER_EXPR_H


#include "astNode.h"
#include "constructs.h"
#include <string>

enum exprType {
    binary = 1, location = 2, literal = 3, enclExpr = 4, unExpr = 5
};

class Expression : public astNode {
protected:
    exprType etype; /* Binary or unary or literal or location */
public:
    Expression() = default;

    exprType getEtype() { return etype; }

    virtual std::string toString() {}

    virtual Value *generateCode(Constructs *compilerConstructs) {}
};

#endif
