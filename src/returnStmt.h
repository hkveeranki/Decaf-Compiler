//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_RETURNSTMT_H
#define DECAF_COMPILER_RETURNSTMT_H

#include "expr.h"
#include "stmt.h"
#include "globals.h"

class returnStmt : public Stmt {
private:
    class Expr *ret;/* Expression to be returned */
public:
    returnStmt(class Expr *);

    Value *codegen(globals *currentGlobals);

    bool has_return() { return true; }
};


#endif //DECAF_COMPILER_RETURNSTMT_H
