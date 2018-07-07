/**
 * class to handle an argument given to the callout statement
 */

#ifndef DECAF_COMPILER_CALLOUTARGUMENT_H
#define DECAF_COMPILER_CALLOUTARGUMENT_H

#include "astNode.h"
#include "expression.h"
#include "constructs.h"
#include <string>

class calloutArgument : public astNode {
private:
    /* Expression which is an argument to the callout statement */
    class Expression *expr;

public:
    explicit calloutArgument(class Expression *);

    explicit calloutArgument(std::string literal);

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
