//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_FORSTATEMENT_H
#define DECAF_COMPILER_FORSTATEMENT_H

#include <string>
#include "block.h"
#include "expression.h"
#include "statement.h"

class forStatement : public Statement {
private:
    std::string var;/* variable to be initialised */
    class Expression *init; /* Value for initialisation */
    class Expression *condition; /* condition for loop */
    class Block *body; /* body of the loop */
public:
    forStatement(std::string, class Expression *, class Expression *, class Block *);

    bool has_return() { this->body->has_return(); }

    Value *generateCode(globals *currentGlobals);
};


#endif
