//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_EXPR_H
#define DECAF_COMPILER_EXPR_H


#include "astNode.h"
#include "globals.h"
#include <string>

enum exprType {
    binary = 1, location = 2, literal = 3, enclExpr = 4, Unexpr = 5
};

class Expr : public astNode {
protected:
    exprType etype; /* Binary or unary or literal or location */
public:

    void setEtype(exprType x) { etype = x; }

    exprType getEtype() { return etype; }

    virtual std::string toString() {}

    virtual Value *codegen(globals *currentGlobals) {}
};

#endif //DECAF_COMPILER_EXPR_H
