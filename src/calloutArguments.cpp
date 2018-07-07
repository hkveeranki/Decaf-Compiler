/**
 * Implementation of the \ref  calloutArguments class
 */

#include "calloutArguments.h"

/**
 * add a given argument to the list of arguments
 * @param arg argument to be added
 */
void calloutArguments::push_back(class calloutArgument *arg) {
    args_list.push_back(arg);
}

/**
 * return the list of arguments in the class
 * @return argument list for the callout statements
 */
std::vector<class calloutArgument *> calloutArguments::getArgsList() {
    return args_list;
}