//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_ASSIGNMENT_H
#define DECAF_COMPILER_ASSIGNMENT_H

#include <string>
#include "stmt.h"
#include "location.h"
#include "globals.h"

class Assignment : public Stmt {
private:
    class Location *loc; /* location to which assignment is done */
    class Expr *expr; /* what is assigned */
    std::string opr; /* how it is assigned = or -= or += */
public:
    Assignment(class Location *, std::string, class Expr *);

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_ASSIGNMENT_H
