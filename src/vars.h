//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_VARS_H
#define DECAF_COMPILER_VARS_H


#include <vector>
#include <llvm/IR/LLVMContext.h>
#include "astNode.h"
#include "var.h"

using namespace std;
using namespace llvm;

class Vars : public astNode {
private:
    vector<class Var *> vars_list;
    int cnt;
public:
    Vars() = default;

    void push_back(class Var *);

    vector<class Var *> getVarsList();

    Value *codegen(globals *currentGlobals);

};


#endif //DECAF_COMPILER_VARS_H
