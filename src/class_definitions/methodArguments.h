//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODARGUMENTS_H
#define DECAF_COMPILER_METHODARGUMENTS_H

#include "astNode.h"
#include "methodArgument.h"
#include "globals.h"
#include <vector>

class methodArguments : public astNode {
private:
    std::vector<class methodArgument *> arg_list;
    int cnt;
public:
    methodArguments();

    void push_back(class methodArgument *);

    std::vector<class methodArgument *> getArgList();

    Value *generateCode(globals *currentGlobals);
};


#endif
