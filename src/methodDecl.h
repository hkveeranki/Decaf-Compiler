//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODDECL_H
#define DECAF_COMPILER_METHODDECL_H

#include "astNode.h"
#include "block.h"
#include "methodArgs.h"
#include "globals.h"
#include <string>
#include <llvm/IR/Function.h>

class methodDecl : public astNode {
private:
    std::string type; /* return type of the function */
    std::string name; /* name of the function */
    class methodArgs *arg_list; /* List of arguments for the functions */
    class Block *body; /* Body of the function */
public:
    methodDecl(std::string type, std::string name, class methodArgs *, class Block *);

    Function *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_METHODDECL_H
