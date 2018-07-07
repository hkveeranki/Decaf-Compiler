/**
 * Class to handle declaration of a field in the class
 */

#ifndef DECAF_COMPILER_FIELDDECLARATION_H
#define DECAF_COMPILER_FIELDDECLARATION_H

#include <vector>
#include <string>

#include "astNode.h"
#include "variables.h"

using namespace std;

class fieldDeclaration : public astNode {
private:
    /* Field declaration can have data type */
    string dataType;
    /* and a list of variables */
    vector<class Variable *> var_list;
public:
    fieldDeclaration(string, class Variables *);

    Value *generateCode(Constructs *compilerConstructs) override;
};

#endif
