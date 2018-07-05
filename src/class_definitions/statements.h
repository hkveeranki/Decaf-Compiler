//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_STMTS_H
#define DECAF_COMPILER_STMTS_H

#include "astNode.h"
#include "statement.h"
#include "globals.h"
#include <vector>

class Statements : public astNode {
private:
    std::vector<class Statement *> stmts;
    int cnt;
public:
    Statements();

    void push_back(class Statement *);

    bool has_return();

    Value *generateCode(globals *currentGlobals);
};

#endif
