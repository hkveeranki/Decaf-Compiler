//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_PARAMS_H
#define DECAF_COMPILER_PARAMS_H

#include "astNode.h"
#include "globals.h"
#include <vector>

class Params : public astNode {
private:
    std::vector<class Expr *> expr_list;
    int cnt;
public:
    Params();

    void push_back(class Expr *);

    std::vector<class Expr *> getExprList();

    Value *codegen(globals *currentGlobals);
};

#endif //DECAF_COMPILER_PARAMS_H
