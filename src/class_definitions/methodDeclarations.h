//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODDECLARATIONS_H
#define DECAF_COMPILER_METHODDECLARATIONS_H

#include "astNode.h"
#include "methodDeclaration.h"
#include "globals.h"
#include <vector>

class methodDeclarations : public astNode {
private:
    std::vector<class methodDeclaration *> decl_list;
    int cnt;
public:
    methodDeclarations();

    void push_back(class methodDeclaration *);

    Value *generateCode(globals* currentGlobals);
};


#endif
