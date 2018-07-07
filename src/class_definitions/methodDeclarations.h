/**
 * class to handle all the method declarations in the decaf program
 */
#ifndef DECAF_COMPILER_METHODDECLARATIONS_H
#define DECAF_COMPILER_METHODDECLARATIONS_H

#include "astNode.h"
#include "methodDeclaration.h"
#include "constructs.h"
#include <vector>

class methodDeclarations : public astNode {
private:
    /* List of method declarations */
    std::vector<class methodDeclaration *> decl_list;
public:
    methodDeclarations() = default;

    void push_back(class methodDeclaration *);

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
