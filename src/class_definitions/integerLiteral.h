/**
 * class to handle integer literals in the code
 */
#ifndef DECAF_COMPILER_INTEGERLITERAL_H
#define DECAF_COMPILER_INTEGERLITERAL_H

#include "literal.h"
#include "constructs.h"

class integerLiteral : public Literal {
private:
    /* Value of the integer value */
    int value;
public:
    explicit integerLiteral(int);

    int getValue() override;

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
