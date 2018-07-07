/**
 * class to deal with variables in a field declaration in the code
 */

#ifndef DECAF_COMPILER_VARIABLE_H
#define DECAF_COMPILER_VARIABLE_H

#include "astNode.h"
#include "utilities.h"
#include <string>

enum variableType {
    Array = 1, Normal = 2
};

class Variable : public astNode {
private:
    /* Type of the variable */
    variableType declType;
    /* Name of the variable */
    std::string name;
    /* if it is an Array then length */
    unsigned int length;
public:
    /* Constructors */
    Variable(std::string, unsigned int);

    explicit Variable(std::string);

    bool isArray() { return (declType == variableType::Array); }

    /* Methods */
    std::string getName();

    unsigned int getLength() { return length; }
};

#endif
