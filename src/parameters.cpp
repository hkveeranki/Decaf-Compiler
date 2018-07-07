/**
 * Implementation of \ref Parameters class
 */
#include "parameters.h"

/**
 * Add a parameter to the list
 * @param param parameter to be added
 */
void Parameters::push_back(class Expression *param) {
    params.push_back(param);
}

/**
 * @return list of parameters
 */
std::vector<class Expression *> Parameters::getParams() {
    return params;
}