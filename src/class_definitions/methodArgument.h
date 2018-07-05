//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODARGUMENT_H
#define DECAF_COMPILER_METHODARGUMENT_H

#include <string>
#include "astNode.h"
#include "globals.h"

class methodArgument : public astNode {
private:
    std::string type; /* type of the argument int/boolean */
    std::string name; /* name of argument */
public:
    methodArgument(std::string, std::string);

    std::string getName();

    std::string getType();

    Value *generateCode(globals *currentGlobals);
};


#endif
