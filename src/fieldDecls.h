//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_FIELDDECLS_H
#define DECAF_COMPILER_FIELDDECLS_H


#include <vector>
#include "astNode.h"
#include "fieldDecl.h"


class fieldDecls : public astNode {
private:
    std::vector<class fieldDecl *> decl_list;
    int cnt;
public:
    fieldDecls();

    void push_back(class fieldDecl *);

    Value *codegen(globals *currentGlobals);
};


#endif //DECAF_COMPILER_FIELDDECLS_H
