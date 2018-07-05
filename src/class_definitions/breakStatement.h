//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_BREAKSTATEMENT_H
#define DECAF_COMPILER_BREAKSTATEMENT_H


#include "statement.h"
#include "globals.h"

class breakStatement : public Statement {
public:
    breakStatement() { this->stype = stmtType::NonReturn; }

    Value *generateCode(globals *currentGlobals);
};

#endif
