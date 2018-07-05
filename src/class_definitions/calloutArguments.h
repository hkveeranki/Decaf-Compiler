//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_CALLOUTARGUMENTS_H
#define DECAF_COMPILER_CALLOUTARGUMENTS_H

#include <vector>
#include "astNode.h"
#include "calloutArgument.h"
#include "globals.h"

class calloutArguments : public astNode {
private:
    std::vector<class calloutArgument *> args_list;
    int cnt;
public:
    calloutArguments();

    void push_back(class calloutArgument *);

    std::vector<class calloutArgument *> getArgsList();

    Value *generateCode(globals *currentGlobals);
};


#endif
