/**
 * class to deal with a set of continous statements in the code
 */

#ifndef DECAF_COMPILER_STMTS_H
#define DECAF_COMPILER_STMTS_H

#include "astNode.h"
#include "statement.h"
#include "constructs.h"
#include <vector>

class Statements : public astNode {
private:
    /* List of statements */
    std::vector<class Statement *> statements_list;
public:
    Statements() = default;

    void push_back(class Statement *);

    bool has_return();
    bool has_break();
    bool has_continue();

    Value *generateCode(Constructs *compilerConstructs) override;
};

#endif
