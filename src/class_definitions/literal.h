/**
 * Abstract class for all the literals present in the code
 */

#ifndef DECAF_COMPILER_LITERAL_H
#define DECAF_COMPILER_LITERAL_H

#include <string>
#include "expression.h"
#include "constructs.h"

/**
 * enum to hold the type of literal
 */
enum literalType {
    Int = 1, Bool = 2, Char = 3, String = 4
};

class Literal : public Expression {
protected:
    /* Integer bool or char or String*/
    literalType ltype;
public:

    virtual int getValue() {}

    virtual Value *generateCode(Constructs *compilerConstructs) {}
};


#endif
