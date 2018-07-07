/**
 * Class to deal with set of variable declarations in the code
 */

#ifndef DECAF_COMPILER_VARIABLEDECLARATIONS_H
#define DECAF_COMPILER_VARIABLEDECLARATIONS_H

#include "astNode.h"
#include "variableDeclaration.h"
#include "constructs.h"
#include <vector>
#include <string>
#include <map>
#include <llvm/IR/Instructions.h>

class variableDeclarations : public astNode {
private:
    /* list of declarations */
    std::vector<class variableDeclaration *> decl_list;
public:
    variableDeclarations() = default;

    void push_back(class variableDeclaration *);

    Value *generateCode(std::map<std::string, llvm::AllocaInst *> &, Constructs *);
};


#endif
