/**
 * Class to deal with break statement present in the code
 */
#ifndef DECAF_COMPILER_BREAKSTATEMENT_H
#define DECAF_COMPILER_BREAKSTATEMENT_H


#include "statement.h"
#include "constructs.h"

class breakStatement : public Statement {
public:
    /**
     * Default constructor which initialises the statement type to NonReturn
     */
    breakStatement() { this->mhas_break=true; this->mhas_return=false; this->mhas_continue=false; }

    Value *generateCode(Constructs *compilerConstructs) override;
};

#endif
