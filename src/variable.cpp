/**
 * Implementation of \ref Variable class
 */

#include <llvm/IR/Constants.h>
#include <llvm/IR/LLVMContext.h>

#include "variable.h"

/**
 * Constructor for the class when variable is an array
 * @param name name of the variable
 * @param array_size size of the array
 */
Variable::Variable(std::string name, unsigned int array_size) {
    this->declType = variableType::Array;
    this->name = std::move(name);
    this->length = array_size;
}

/**
 * Constructor for the class when variable is non array
 * @param name name of the variable
 */
Variable::Variable(std::string name) {
    this->declType = variableType::Normal;
    this->name = std::move(name);
}

/**
 * @return name of the variable
 */
string Variable::getName() {
    return name;
}
