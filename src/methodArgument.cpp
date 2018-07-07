/**
 * Implementation of \ref methodArgument class
 */

#include <utility>
#include <string>
#include "methodArgument.h"

/**
 * Constructor for the class
 * @param type type of the argument
 * @param name name of the argument
 */
methodArgument::methodArgument(std::string type, std::string name) {
    this->type = std::move(type);
    this->name = std::move(name);
}

/**
 * Return the name of the argument
 * @return string which contains name of the argument
 */
std::string methodArgument::getName() {
    return name;
}

/**
 * Return the type of the argument
 * @return string which contains type of the argument "int" or "boolean"
 */
std::string methodArgument::getType() {
    return type;
}
