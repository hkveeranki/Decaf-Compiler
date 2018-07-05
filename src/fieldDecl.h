//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_FIELDDECL_H
#define DECAF_COMPILER_FIELDDECL_H

#include <vector>
#include <string>

#include "astNode.h"
#include "vars.h"

using namespace std;

class fieldDecl : public astNode {
private:
    string dataType; /* Field declaration can have datatype and vaariables */
    vector<class Var *> var_list;
public:
    fieldDecl(string, class Vars *);

    vector<class Var *> getVarsList();

    Value *codegen(globals* currentGlobals);
};

#endif //DECAF_COMPILER_FIELDDECL_H
