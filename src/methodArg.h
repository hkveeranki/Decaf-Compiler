//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODARG_H
#define DECAF_COMPILER_METHODARG_H

#include <string>
#include "astNode.h"
#include "globals.h"

class methodArg : public astNode {
private:
    std::string type; /* type of the argument int/boolean */
    std::string name; /* name of argument */
public:
    methodArg(std::string, std::string);

    std::string getName();

    std::string getType();

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_METHODARG_H
