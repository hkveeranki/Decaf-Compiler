//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_VARIABLE_H
#define DECAF_COMPILER_VARIABLE_H

#include "astNode.h"
#include "utilities.h"
#include <string>

using namespace std;

class Variable : public astNode {
private:
    string declType; /* Array or Normal */
    string name; /* Name of the variable */
    string dataType; /* type of variable */
    unsigned int length; /* if it is an Array then length */
public:
    /* Constructors */
    Variable(string, string, unsigned int);

    Variable(string, string);

    bool isArray();

    /* Methods */
    void setDataType(string); /* Set the data Type */

    string getName();

    unsigned int getLength() { return length; }

    Value *generateCode(globals *currentGlobals);
};

#endif
