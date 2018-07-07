/**
 * Abstract class to deal with functions calls in the code namely method calls and callout calls
 */

#ifndef DECAF_COMPILER_FUNCTIONCALL_H
#define DECAF_COMPILER_FUNCTIONCALL_H

#include <string>
#include "statement.h"
#include "expression.h"
#include "constructs.h"

class functionCall : public Statement, public Expression {
protected:
    std::string method_name;
public:
    Value *generateCode(Constructs *compilerConstructs) override {}
};


#endif
