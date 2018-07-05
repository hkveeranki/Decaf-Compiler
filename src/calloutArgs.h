//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_CALLOUTARGS_H
#define DECAF_COMPILER_CALLOUTARGS_H

#include <vector>
#include "astNode.h"
#include "calloutArg.h"
#include "globals.h"

class calloutArgs : public astNode {
private:
    std::vector<class calloutArg *> args_list;
    int cnt;
public:
    calloutArgs();

    void push_back(class calloutArg *);

    std::vector<class calloutArg *> getArgsList();

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_CALLOUTARGS_H
