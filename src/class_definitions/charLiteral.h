/**
 * class to handle character literals present in the code
 */
#ifndef DECAF_COMPILER_CHARLITERAL_H
#define DECAF_COMPILER_CHARLITERAL_H


#include "literal.h"

class charLiteral : public Literal {
private:
    char value;
public:
    explicit charLiteral(std::string);
};

#endif
