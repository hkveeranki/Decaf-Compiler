/**
 * class to deal with all field declarations in a decaf class
 */

#ifndef DECAF_COMPILER_FIELDDECLARATIONS_H
#define DECAF_COMPILER_FIELDDECLARATIONS_H


#include <vector>
#include "astNode.h"
#include "fieldDeclaration.h"


class fieldDeclarations : public astNode {
private:
    /* List of all declarations */
    std::vector<class fieldDeclaration *> declaration_list;
public:
    fieldDeclarations() = default;

    void push_back(class fieldDeclaration *);

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
