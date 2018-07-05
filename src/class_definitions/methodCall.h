//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODCALL_H
#define DECAF_COMPILER_METHODCALL_H

#include <string>
#include "statement.h"
#include "expression.h"
#include "globals.h"

class methodCall : public Statement, public Expression {
protected:
    std::string method_name;
public:
    virtual Value *generateCode(globals *currentGlobals) {}
};


#endif
