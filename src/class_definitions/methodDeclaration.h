/**
 * class to deal method declarations in a Decaf program
 */

#ifndef DECAF_COMPILER_METHODDECLARATION_H
#define DECAF_COMPILER_METHODDECLARATION_H

#include "astNode.h"
#include "block.h"
#include "methodArguments.h"
#include "constructs.h"
#include <string>
#include <llvm/IR/Function.h>

class methodDeclaration : public astNode {
private:
    /* return type of the function */
    std::string return_type;
    /* name of the function */
    std::string name;

    /* List of arguments for the functions */
    class methodArguments *arg_list;

    /* Body of the function */
    class Block *body;

public:
    methodDeclaration(std::string return_type, std::string name, class methodArguments *, class Block *);

    Function *generateCode(Constructs *compilerConstructs) override;
};


#endif
