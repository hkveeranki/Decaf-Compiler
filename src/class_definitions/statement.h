/**
 * Abstract class to deal with all types of statements in the code
 */

#ifndef DECAF_COMPILER_STATEMENT_H
#define DECAF_COMPILER_STATEMENT_H


#include "astNode.h"
#include "constructs.h"

enum stmtType {
    Return = 1, NonReturn = 2
};


class Statement : public astNode {
protected:
    stmtType stype;
public:
    Statement() { stype = stmtType::NonReturn; }

    Value *generateCode(Constructs *compilerConstructs) override {}

    virtual bool has_return() { return false; }

};

#endif
