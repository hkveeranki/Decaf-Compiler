//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_VARDECLS_H
#define DECAF_COMPILER_VARDECLS_H

#include "astNode.h"
#include "varDecl.h"
#include "globals.h"
#include <vector>
#include <string>
#include <map>
#include <llvm/IR/Instructions.h>

class varDecls : public astNode {
private:
    std::vector<class varDecl *> decl_list;
    int cnt;
public:
    varDecls();

    void push_back(class varDecl *);

    Value *codegen(map<string, AllocaInst *> &, globals *);
};


#endif //DECAF_COMPILER_VARDECLS_H
