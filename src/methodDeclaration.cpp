/**
 * Implementation of \ref methodDeclaration class
 */

#include <llvm/IR/Verifier.h>
#include <llvm/IR/CFG.h>
#include "methodDeclaration.h"
#include "utilities.h"

/**
 * Constructor for the class
 * @param return_type return type of the function can be "int", "boolean" or "void"
 * @param name name of the function
 * @param args list of arguments for the function
 * @param block body of the function
 */
methodDeclaration::methodDeclaration(std::string return_type, std::string name, class methodArguments *args,
                                     class Block *block) {
    this->return_type = std::move(return_type);
    this->name = std::move(name);
    this->arg_list = args;
    this->body = block;
}

/**
 * Split the given basic block into two blocks
 * @param basicBlock Basic block which should be split
 * @param it iterator to instruction from which the block should be split
 * @return new block which is obtained after the split
 */
llvm::BasicBlock *splitBlock(llvm::BasicBlock *basicBlock, llvm::BasicBlock::iterator it) {

    /// Double
    assert(basicBlock->getTerminator() && "Block must have terminator instruction.");
    assert(it != basicBlock->end() &&
           "Can't split block since there is no following instruction in the basic block.");

    auto newBlock = llvm::BasicBlock::Create(basicBlock->getContext(), "splitedBlock", basicBlock->getParent(),
                                             basicBlock->getNextNode());

    // Move all of the instructions from original block into new block.
    newBlock->splice(newBlock->end(), basicBlock, it, basicBlock->end());

    // Now we must loop through all of the successors of the New block (which
    // _were_ the successors of the 'this' block), and update any PHI nodes in
    // successors.  If there were PHI nodes in the successors, then they need to
    // know that incoming branches will be from New, not from Old.
    //
    for (llvm::succ_iterator I = llvm::succ_begin(newBlock), E = llvm::succ_end(newBlock); I != E; ++I) {
        // Loop over any phi nodes in the basic block, updating the BB field of
        // incoming values...
        llvm::BasicBlock *Successor = *I;
        for (auto &PN : Successor->phis()) {
            int Idx = PN.getBasicBlockIndex(basicBlock);
            while (Idx != -1) {
                PN.setIncomingBlock((unsigned) Idx, newBlock);
                Idx = PN.getBasicBlockIndex(basicBlock);
            }
        }
    }

    return newBlock;
}

/**
 * Remove dead code from a basic block
 * @param basicBlock
 */
void removeDeadCode(BasicBlock *basicBlock) {

    for (auto it = basicBlock->begin(); it != basicBlock->end(); ++it) {
        // Check the first terminator instruction
        if (it->isTerminator()) {
            ++it;
            // Check if there is any code after the terminator
            if (it != basicBlock->end()) {
                // If there is, then split into live and dead code
                auto deadCodeBlock = splitBlock(basicBlock, it);
                // Remove the dead code block gracefully
                deadCodeBlock->eraseFromParent();
            }
            return;
        }
    }
}

Function *methodDeclaration::generateCode(Constructs *compilerConstructs) {
    std::vector<std::string> argNames;
    std::vector<std::string> argTypes;
    std::vector<class methodArgument *> args = arg_list->getArgList();
    std::vector<Type *> arguments;
    auto arg_size = args.size();
    for (auto &arg : args) {
        /* Iterate over the arguments and get the types of them in llvm */
        std::string arg_type = arg->getType();
        std::string arg_name = arg->getName();
        if (arg_type == "int") {
            arguments.push_back(Type::getInt32Ty(compilerConstructs->Context));
        } else if (arg_type == "boolean") {
            arguments.push_back(Type::getInt1Ty(compilerConstructs->Context));
        } else {
            compilerConstructs->errors++;
            reportError("Arguments can only be int or boolean");
            return nullptr;
        }
        argTypes.emplace_back(arg_type);
        argNames.emplace_back(arg_name);
    }

    Type *returnType;
    /* Get the return Type */
    if (return_type == "int") {
        returnType = Type::getInt32Ty(compilerConstructs->Context);
    } else if (return_type == "boolean") {
        returnType = Type::getInt1Ty(compilerConstructs->Context);
    } else if (return_type == "void") {
        returnType = Type::getVoidTy(compilerConstructs->Context);
    } else {
        compilerConstructs->errors++;
        reportError("Invalid Return Type for " + name + ". Return Type can only be int or boolean or bool");
        return nullptr;
    }

    /* Get the function type and create a Function */
    FunctionType *FT = llvm::FunctionType::get(returnType, arguments, false);
    Function *F = llvm::Function::Create(FT, Function::ExternalLinkage, name, compilerConstructs->TheModule);

    /* Iterate through arguments and set the Names for them */

    unsigned Idx = 0;
    for (Function::arg_iterator AI = F->arg_begin(); Idx != arg_size; ++AI, ++Idx) {
        AI->setName(argNames[Idx]);
    }

    /* Create a New block for this Function */
    BasicBlock *BB = BasicBlock::Create(compilerConstructs->Context, "entry", F);
    compilerConstructs->Builder->SetInsertPoint(BB);
    Idx = 0;

    /* Allocate memory for the arguments passed */
    for (auto &Arg : F->args()) {
        AllocaInst *Alloca = compilerConstructs->CreateEntryBlockAlloca(F, argNames[Idx], argTypes[Idx]);
        compilerConstructs->Builder->CreateStore(&Arg, Alloca);
        compilerConstructs->NamedValues[argNames[Idx]] = Alloca;
        ++Idx;
    }
    Value *RetVal = body->generateCode(compilerConstructs);
    if (RetVal) {
        /* make this the return value */        
        if (return_type != "void")
            compilerConstructs->Builder->CreateRet(RetVal);
        else
            compilerConstructs->Builder->CreateRetVoid();
        // Iterate through each basic block in this function and remove any dead code
        for (auto &basicBlock : *F) {
            BasicBlock *block = &basicBlock;
            removeDeadCode(block);
        }
        /* Verify the function */
        verifyFunction(*F);
        // compilerConstructs->TheFPM->run(*F, *compilerConstructs->TheFAM);
        return F;
    }
    /* In case of errors remove the function */
    F->eraseFromParent();
    return nullptr;
}
