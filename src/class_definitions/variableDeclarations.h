//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_VARIABLEDECLARATIONS_H
#define DECAF_COMPILER_VARIABLEDECLARATIONS_H

#include "astNode.h"
#include "variableDeclaration.h"
#include "globals.h"
#include <vector>
#include <string>
#include <map>
#include <llvm/IR/Instructions.h>

class variableDeclarations : public astNode {
private:
    std::vector<class variableDeclaration *> decl_list;
    int cnt;
public:
    variableDeclarations();

    void push_back(class variableDeclaration *);

    Value *generateCode(std::map<std::string, llvm::AllocaInst *> &, globals *);
};


#endif
