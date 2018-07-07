/**
 * class to deal with boolean literals present in the code
 */

#ifndef DECAF_COMPILER_BOOLLITERAL_H
#define DECAF_COMPILER_BOOLLITERAL_H

#include <string>
#include "literal.h"
#include "constructs.h"

class boolLiteral : public Literal {
private:
    std::string value;
public:
    explicit boolLiteral(std::string value);

    Value *generateCode(Constructs *compilerConstructs) override;
};

#endif
