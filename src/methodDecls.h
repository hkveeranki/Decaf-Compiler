//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHODDECLS_H
#define DECAF_COMPILER_METHODDECLS_H

#include "astNode.h"
#include "methodDecl.h"
#include "globals.h"
#include <vector>

class methodDecls : public astNode {
private:
    std::vector<class methodDecl *> decl_list;
    int cnt;
public:
    methodDecls();

    void push_back(class methodDecl *);

    Value *codegen(globals* currentGlobals);
};


#endif //DECAF_COMPILER_METHODDECLS_H
