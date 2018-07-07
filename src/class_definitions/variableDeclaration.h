/**
 * class to deal variable declarations in the code
 */

#ifndef DECAF_COMPILER_VARIABLEDECLARATION_H
#define DECAF_COMPILER_VARIABLEDECLARATION_H

#include "astNode.h"
#include "stringList.h"
#include "constructs.h"
#include <llvm/IR/Instructions.h>
#include <map>
#include <string>
#include <vector>


class variableDeclaration : public astNode {
private:
    /* type of variable declaraion */
    std::string type;
    /* list of variables */
    std::vector<std::string> var_list;
public:
    variableDeclaration(std::string, class stringList *);

    void push_back(std::string);

    Value *generateCode(std::map<std::string, llvm::AllocaInst *> &, Constructs *);
};


#endif
