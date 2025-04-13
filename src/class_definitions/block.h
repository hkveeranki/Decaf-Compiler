/**
 * Class to deal with blocks of code in the program. Deals with code
 * assosciated within if else statements or a for loop
 */
#ifndef DECAF_COMPILER_BLOCK_H
#define DECAF_COMPILER_BLOCK_H

#include "statement.h"
#include "constructs.h"

class Block : public Statement {
private:
    /* list of variable declarations */
    class variableDeclarations *declarations_list;

    /* list of statements */
    class Statements *statements_list;

public:
    Block(class variableDeclarations *, class Statements *);

    bool has_return() override;
    bool has_break() override;
    bool has_continue() override;
    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
