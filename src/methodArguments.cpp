/**
 * Implementation of \ref methodArguments class
 */
#include <vector>
#include "methodArguments.h"

/**
 * @return list of arguments for the given method
 */
std::vector<class methodArgument *> methodArguments::getArgList() {
    return arg_list;
}

/**
 * Add an argument to the list of arguments
 * @param arg method argument to be added
 */
void methodArguments::push_back(class methodArgument *arg) {
    arg_list.push_back(arg);
}

