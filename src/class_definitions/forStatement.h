/**
 * class to deal with for statements in the code
 */

#ifndef DECAF_COMPILER_FORSTATEMENT_H
#define DECAF_COMPILER_FORSTATEMENT_H

#include <string>
#include "block.h"
#include "expression.h"
#include "statement.h"

class forStatement : public Statement {
private:
    /* variable to be initialised */
    std::string var;

    /* Value for initialisation */
    class Expression *init;

    /* condition for loop */
    class Expression *condition;

    /* body of the loop */
    class Block *body;

public:
    forStatement(std::string, class Expression *, class Expression *, class Block *);

    bool has_return() override { return this->body->has_return(); }
    bool has_break() override { return this->body->has_break(); }
    bool has_continue() override { return this->body->has_continue(); }
    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
