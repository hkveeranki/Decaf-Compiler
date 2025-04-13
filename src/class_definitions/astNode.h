/**
 * Abstract class for all AST nodes
 */
#ifndef DECAF_COMPILER_ASTNODE_H
#define DECAF_COMPILER_ASTNODE_H

#include <llvm/IR/Value.h>
#include "constructs.h"
#include <iostream>

using namespace llvm;

class astNode {
    /**
     * Generate the intermediate representation for the node
     * @param compilerConstructs an instance of the Constructs class which contains the data required for building the IR
     * @return generated IR representation
     */
    virtual Value *generateCode(Constructs *compilerConstructs) {}

};

#endif
