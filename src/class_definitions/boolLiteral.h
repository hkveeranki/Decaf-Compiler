//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_BOOLLITERAL_H
#define DECAF_COMPILER_BOOLLITERAL_H

#include <string>
#include "literal.h"
#include "globals.h"

class boolLiteral : public Literal {
private:
    std::string value;
public:
    explicit boolLiteral(std::string value);

    Value *generateCode(globals *currentGlobals);
};

#endif
