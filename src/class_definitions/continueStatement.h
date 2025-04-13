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
    continueStatement() { this->mhas_continue = true; this->mhas_return = false; this->mhas_break = false; }

    Value *generateCode(Constructs *compilerConstructs) override;
};

#endif
