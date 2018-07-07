/**
 * Implementation of \ref stringList class
 */
#include <string>
#include <vector>
#include "stringList.h"

/**
 * Add a string to the list of strings
 * @param var string to be added
 */
void stringList::push_back(std::string var) {
    list.push_back(var);
}

/**
 * @return the list of strings
 */
std::vector<std::string> stringList::getList() {
    return this->list;
}
