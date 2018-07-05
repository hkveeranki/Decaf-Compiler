//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_VARIABLES_H
#define DECAF_COMPILER_VARIABLES_H


#include <vector>
#include <llvm/IR/LLVMContext.h>
#include "astNode.h"
#include "variable.h"

using namespace std;
using namespace llvm;

class Variables : public astNode {
private:
    vector<class Variable *> vars_list;
    int cnt;
public:
    Variables() = default;

    void push_back(class Variable *);

    vector<class Variable *> getVarsList();

    Value *generateCode(globals *currentGlobals);

};


#endif
