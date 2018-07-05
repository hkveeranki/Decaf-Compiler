//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_BREAKSTMT_H
#define DECAF_COMPILER_BREAKSTMT_H


#include "stmt.h"
#include "globals.h"

class breakStmt : public Stmt {
public:
    breakStmt() { this->stype = stmtType::NonReturn; }

    Value *codegen(globals *currentGlobals);
};

#endif //DECAF_COMPILER_BREAKSTMT_H
