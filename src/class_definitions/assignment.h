/**
 * Class to deal with assignment operations in the code
 */

#ifndef DECAF_COMPILER_ASSIGNMENT_H
#define DECAF_COMPILER_ASSIGNMENT_H

#include <string>
#include "statement.h"
#include "location.h"
#include "constructs.h"

class Assignment : public Statement {
private:
    /* location to which assignment is done */
    class Location *loc;

    /* what is assigned */
    class Expression *expr;

    /* how it is assigned = or -= or += */
    std::string opr;
public:
    Assignment(class Location *, std::string, class Expression *);

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
