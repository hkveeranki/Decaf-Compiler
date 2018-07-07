/**
 * Class to handle all the arguments defined in a method declaration
 */

#ifndef DECAF_COMPILER_METHODARGUMENTS_H
#define DECAF_COMPILER_METHODARGUMENTS_H

#include "astNode.h"
#include "methodArgument.h"
#include "constructs.h"
#include <vector>

class methodArguments : public astNode {
private:
    /* List of all arguments */
    std::vector<class methodArgument *> arg_list;
public:
    methodArguments() = default;

    void push_back(class methodArgument *);

    std::vector<class methodArgument *> getArgList();
};


#endif
