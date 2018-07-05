//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_CALLOUTARGUMENT_H
#define DECAF_COMPILER_CALLOUTARGUMENT_H

#include "astNode.h"
#include "expression.h"
#include "globals.h"
#include <string>

class calloutArgument : public astNode {
private:
    class Expression *expr;

public:
    explicit calloutArgument(class Expression *);

    explicit calloutArgument(std::string literal);

    Value *generateCode(globals *currentGlobals);
};


#endif
