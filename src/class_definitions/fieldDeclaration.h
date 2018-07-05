//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_FIELDDECLARATION_H
#define DECAF_COMPILER_FIELDDECLARATION_H

#include <vector>
#include <string>

#include "astNode.h"
#include "variables.h"

using namespace std;

class fieldDeclaration : public astNode {
private:
    string dataType; /* Field declaration can have datatype and vaariables */
    vector<class Variable *> var_list;
public:
    fieldDeclaration(string, class Variables *);

    vector<class Variable *> getVarsList();

    Value *generateCode(globals* currentGlobals);
};

#endif
