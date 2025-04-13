//
// Created by harry7 on 7/5/18.
//

#ifndef DECAF_COMPILER_CONSTRUCTS_H
#define DECAF_COMPILER_CONSTRUCTS_H

#include <map>
#include <string>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <string>
#include <stack>

using namespace llvm;

class loopInfo {
    BasicBlock *afterBB, *checkBB;
    llvm::Value *condition;
    std::string loopVariable;
    PHINode *phiVariable;
public:
    loopInfo(BasicBlock *afterBlock, BasicBlock *checkBlock, Value *cond, std::string var, PHINode *phiVar) {
        afterBB = afterBlock;
        checkBB = checkBlock;
        condition = cond;
        loopVariable = var;
        phiVariable = phiVar;
    }

    BasicBlock *getAfterBlock() { return afterBB; }

    BasicBlock *getCheckBlock() { return checkBB; }

    llvm::Value *getCondition() { return condition; }

    PHINode *getPHINode() { return phiVariable; }

    std::string getLoopVariable() { return loopVariable; }
};

class Constructs {
public:
    /**
     * Context is an opaque object that owns a lot of core LLVM data structures, such as the type and
     * constant value tables.
     */
    LLVMContext Context;
    /**
     * TheModule is an LLVM construct that contains functions and global variables.
     * In many ways, it is the top-level structure that the LLVM IR uses to contain code.
     * It will own the memory for all of the IR that we generate.
     */
    Module *TheModule;
    /**
     * The Builder object is a helper object that makes it easy to generate LLVM instructions. Instances of the
     * IRBuilder class template keep track of the current place to insert instructions and has methods
     * to create new instructions.
     */
    IRBuilder<> *Builder;
    /**
     * The NamedValues map keeps track of which values are defined in the current scope and what their
     * LLVM representation is. (In other words, it is a symbol table for the code). In this form of Kaleidoscope,
     * the only things that can be referenced are function parameters. As such, function parameters will be in this map
     * when generating code for their function body.
     */
    std::map<std::string, llvm::AllocaInst *> NamedValues;
    /**
     * A FunctionPassManager to hold and organize the LLVM optimizations that we want to run
     */
    FunctionPassManager *TheFPM;

    FunctionAnalysisManager *TheFAM;
    /**
     * Number of errors occured during IR generation
     */
    int errors;

    std::stack<loopInfo *> *loops;

    Constructs();

    AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, std::string VarName, std::string type);

};

#endif
