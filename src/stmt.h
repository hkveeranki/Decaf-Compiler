//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_STMT_H
#define DECAF_COMPILER_STMT_H


#include "astNode.h"
#include "globals.h"

enum stmtType {
    Return = 1, NonReturn = 2
};


class Stmt : public astNode {
protected:
    stmtType stype;
public:
    virtual void traverse() {}

    virtual Value *codegen(globals *currentGlobals) {}

    virtual bool has_return() { return false; }

    void setStype(stmtType x) { this->stype = x; }

    stmtType getStype() { return this->stype; }
};

#endif //DECAF_COMPILER_STMT_H
