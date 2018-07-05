//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_PARAMETERS_H
#define DECAF_COMPILER_PARAMETERS_H

#include "astNode.h"
#include "globals.h"
#include <vector>

class Parameters : public astNode {
private:
    std::vector<class Expression *> expr_list;
    int cnt;
public:
    Parameters();

    void push_back(class Expression *);

    std::vector<class Expression *> getExprList();

    Value *generateCode(globals *currentGlobals);
};

#endif
