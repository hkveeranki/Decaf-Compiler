//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_STRINGLITERAL_H
#define DECAF_COMPILER_STRINGLITERAL_H

#include  "literal.h"
#include "globals.h"
#include <string>

class stringLiteral : public Literal {
private:
    std::string value;
public:
    stringLiteral(std::string);

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_STRINGLITERAL_H
