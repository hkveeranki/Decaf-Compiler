/**
 * class to deal with argument defined in the definition of the method
 */
#ifndef DECAF_COMPILER_METHODARGUMENT_H
#define DECAF_COMPILER_METHODARGUMENT_H

#include <string>
#include "astNode.h"
#include "constructs.h"

class methodArgument : public astNode {
private:
    /* type of the argument int/boolean */
    std::string type;
    /* name of argument */
    std::string name;
public:
    methodArgument(std::string, std::string);

    std::string getName();

    std::string getType();
};


#endif
