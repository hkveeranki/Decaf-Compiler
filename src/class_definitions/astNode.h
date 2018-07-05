//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_ASTNODE_H
#define DECAF_COMPILER_ASTNODE_H

#include <llvm/IR/Value.h>

using namespace llvm;

class astNode {
    virtual Value *generateCode() {}

};

#endif
