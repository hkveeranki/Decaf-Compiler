//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_RETURNSTATEMENT_H
#define DECAF_COMPILER_RETURNSTATEMENT_H

#include "expression.h"
#include "statement.h"
#include "globals.h"

class returnStatement : public Statement {
private:
    class Expression *ret;/* Expression to be returned */
public:
    returnStatement(class Expression *);

    Value *generateCode(globals *currentGlobals);

    bool has_return() { return true; }
};


#endif
