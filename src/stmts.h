//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_STMTS_H
#define DECAF_COMPILER_STMTS_H

#include "astNode.h"
#include "stmt.h"
#include "globals.h"
#include <vector>

class Stmts : public astNode {
private:
    std::vector<class Stmt *> stmts;
    int cnt;
public:
    Stmts();

    void push_back(class Stmt *);

    bool has_return();

    Value *codegen(globals *currentGlobals);
};

#endif //DECAF_COMPILER_STMTS_H
