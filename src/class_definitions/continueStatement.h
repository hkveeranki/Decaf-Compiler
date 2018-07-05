//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_CONTINUESTATEMENT_H
#define DECAF_COMPILER_CONTINUESTATEMENT_H

#include "statement.h"
#include "globals.h"

class continueStatement : public Statement {
public:
    continueStatement() { this->stype = stmtType::NonReturn; }

    Value *generateCode(globals *currentGlobals);
};

#endif
