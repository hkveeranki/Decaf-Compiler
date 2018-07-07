/**
 * class to deal with list of variables in a field declaration in the code
 */

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
    /// list of variables
    vector<class Variable *> vars_list;
public:
    Variables() = default;

    void push_back(class Variable *);

    vector<class Variable *> getVarsList();
};


#endif
