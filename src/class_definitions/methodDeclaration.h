//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODDECLARATION_H
#define DECAF_COMPILER_METHODDECLARATION_H

#include "astNode.h"
#include "block.h"
#include "methodArguments.h"
#include "globals.h"
#include <string>
#include <llvm/IR/Function.h>

class methodDeclaration : public astNode {
private:
    std::string type; /* return type of the function */
    std::string name; /* name of the function */
    class methodArguments *arg_list; /* List of arguments for the functions */
    class Block *body; /* Body of the function */
public:
    methodDeclaration(std::string type, std::string name, class methodArguments *, class Block *);

    Function *generateCode(globals *currentGlobals);
};


#endif
