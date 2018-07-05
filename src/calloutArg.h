//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_CALLOUTARG_H
#define DECAF_COMPILER_CALLOUTARG_H

#include "astNode.h"
#include "expr.h"
#include "globals.h"
#include <string>

class calloutArg : public astNode {
private:
    class Expr *expr;

public:
    explicit calloutArg(class Expr *);

    explicit calloutArg(std::string literal);

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_CALLOUTARG_H
