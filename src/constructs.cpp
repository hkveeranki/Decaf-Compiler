/**
 * Implementation of \ref Constructs class
 */

#include "constructs.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Scalar/Reassociate.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"

/**
 * Constructor for the class
 * Initialises the fields
 */
Constructs::Constructs() {
    this->Builder = new IRBuilder<>(Context);
    this->loops = new std::stack<loopInfo*>();
    errors = 0;
    this->TheModule = new Module("Decaf compiler", Context);
    TheFPM = new FunctionPassManager();
    TheFAM = new FunctionAnalysisManager();
    // TheFPM->addPass(InstCombinePass());
    // // Reassociate expressions.
    // TheFPM->addPass(ReassociatePass());
    // // Eliminate Common SubExpressions.
    // TheFPM->addPass(createGVNPass());
    // // Simplify the control flow graph (deleting unreachable blocks, etc).
    // TheFPM->addPass(createCFGSimplificationPass());
}

/**
 * Allocates memory for local variables on the stack of the function by creating an alloca instruction
 * @param TheFunction Function whose local variable is to allocated memory
 * @param VarName name of the variable
 * @param type type of the variable
 * @return alloca instruction for creating memory for given variable in the given function
 */
AllocaInst *Constructs::CreateEntryBlockAlloca(Function *TheFunction, std::string VarName, std::string type) {
    /* Get the builder for current context */
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *alloca_instruction = nullptr;
    if (type == "int") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt32Ty(this->Context), 0, VarName);
    } else if (type == "boolean") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt1Ty(this->Context), 0, VarName);
    }
    return alloca_instruction;
}
