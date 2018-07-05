//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODARGS_H
#define DECAF_COMPILER_METHODARGS_H

#include "astNode.h"
#include "methodArg.h"
#include "globals.h"
#include <vector>

class methodArgs : public astNode {
private:
    std::vector<class methodArg *> arg_list;
    int cnt;
public:
    methodArgs();

    void push_back(class methodArg *);

    std::vector<class methodArg *> getArgList();

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_METHODARGS_H
