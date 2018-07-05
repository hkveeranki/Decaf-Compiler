//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_FIELDDECLARATIONS_H
#define DECAF_COMPILER_FIELDDECLARATIONS_H


#include <vector>
#include "astNode.h"
#include "fieldDeclaration.h"


class fieldDeclarations : public astNode {
private:
    std::vector<class fieldDeclaration *> decl_list;
    int cnt;
public:
    fieldDeclarations();

    void push_back(class fieldDeclaration *);

    Value *generateCode(globals *currentGlobals);
};


#endif
