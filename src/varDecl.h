//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_VARDECL_H
#define DECAF_COMPILER_VARDECL_H

#include "astNode.h"
#include "stringList.h"
#include "globals.h"
#include <llvm/IR/Instructions.h>
#include <map>
#include <string>
#include <vector>


class varDecl : public astNode {
private:
    std::string type; /* type of variable declaraion */
    std::vector<std::string> var_list; /* list of variables */
    int cnt;
public:
    varDecl(std::string, class stringList *);

    void push_back(std::string);

    Value *codegen(std::map<std::string, llvm::AllocaInst *> &, globals *);
};


#endif //DECAF_COMPILER_VARDECL_H
