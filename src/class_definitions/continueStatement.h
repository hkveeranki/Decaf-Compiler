/**
 * class to handle `continue` statements in the code
 */

#ifndef DECAF_COMPILER_CONTINUESTATEMENT_H
#define DECAF_COMPILER_CONTINUESTATEMENT_H

#include "statement.h"
#include "constructs.h"

class continueStatement : public Statement {
public:
    /**
     * Constructor for the class
     */
    continueStatement() { this->stype = stmtType::NonReturn; }

    Value *generateCode(Constructs *compilerConstructs) override;
};

#endif
