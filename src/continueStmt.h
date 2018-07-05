//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_CONTINUESTMT_H
#define DECAF_COMPILER_CONTINUESTMT_H

#include "stmt.h"
#include "globals.h"

class continueStmt : public Stmt {
public:
    continueStmt() { this->stype = stmtType::NonReturn; }

    Value *codegen(globals *currentGlobals);
};

#endif //DECAF_COMPILER_CONTINUESTMT_H
