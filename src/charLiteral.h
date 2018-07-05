//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_CHARLITERAL_H
#define DECAF_COMPILER_CHARLITERAL_H


#include "literal.h"

class charLiteral : public Literal {
private:
    char value;
public:
    explicit charLiteral(std::string);
};

#endif //DECAF_COMPILER_CHARLITERAL_H
