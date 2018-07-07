/**
 * Implementation of \ref Variables class
 */

#include <llvm/IR/Constants.h>

#include "variables.h"

/**
 * @return list of variables
 */
vector<class Variable *> Variables::getVarsList() {
    return vars_list;
}

/**
 * add a variable to the list of variables
 * @param var variable to be added
 */
void Variables::push_back(class Variable *var) {
    vars_list.push_back(var);
}