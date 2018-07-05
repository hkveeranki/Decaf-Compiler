//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_VAR_H
#define DECAF_COMPILER_VAR_H

#include "astNode.h"
#include "utilities.h"
#include <string>

using namespace std;

class Var : public astNode {
private:
    string declType; /* Array or Normal */
    string name; /* Name of the variable */
    string dataType; /* type of variable */
    unsigned int length; /* if it is an Array then length */
public:
    /* Constructors */
    Var(string, string, unsigned int);

    Var(string, string);

    bool isArray();

    /* Methods */
    void setDataType(string); /* Set the data Type */

    string getName();

    unsigned int getLength() { return length; }

    Value *codegen(globals *currentGlobals);
};

#endif //DECAF_COMPILER_VAR_H
