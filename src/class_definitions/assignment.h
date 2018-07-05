//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_ASSIGNMENT_H
#define DECAF_COMPILER_ASSIGNMENT_H

#include <string>
#include "statement.h"
#include "location.h"
#include "globals.h"

class Assignment : public Statement {
private:
    class Location *loc; /* location to which assignment is done */
    class Expression *expr; /* what is assigned */
    std::string opr; /* how it is assigned = or -= or += */
public:
    Assignment(class Location *, std::string, class Expression *);

    Value *generateCode(globals *currentGlobals);
};


#endif
