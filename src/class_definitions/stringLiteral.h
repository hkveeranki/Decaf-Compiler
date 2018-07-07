/**
 * class to deal with string literals in the code
 */
#ifndef DECAF_COMPILER_STRINGLITERAL_H
#define DECAF_COMPILER_STRINGLITERAL_H

#include  "literal.h"
#include "constructs.h"
#include <string>

class stringLiteral : public Literal {
private:
    /* Value of the literal */
    std::string value;
public:
    explicit stringLiteral(std::string);

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
