//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_LITERAL_H
#define DECAF_COMPILER_LITERAL_H

#include <string>
#include "expr.h"
#include "globals.h"

enum literalType {
    Int = 1, Bool = 2, Char = 3, String = 4
};

class Literal : public Expr {
protected:
    literalType ltype; /* Integer bool or char */
public:

    virtual int getValue() {}

    virtual Value *codegen(globals *currentGlobals) {}
};


#endif //DECAF_COMPILER_LITERAL_H
