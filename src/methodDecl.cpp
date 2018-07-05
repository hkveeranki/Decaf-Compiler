//
// Created by harry7 on 7/4/18.
//

#include <llvm/IR/Verifier.h>
#include "methodDecl.h"
#include "utilities.h"

methodDecl::methodDecl(string ret_type, string name, class methodArgs *args, class Block *block) {
    this->type = ret_type;
    this->name = name;
    this->arg_list = args;
    this->body = block;
}


Function *methodDecl::codegen(globals *currentGlobals) {
    vector<string> argNames;
    vector<string> argTypes;
    vector<class methodArg *> args = arg_list->getArgList();
    vector<Type *> arguments;
    int arg_size = args.size();
    for (int i = 0; i < args.size(); i++) {
        /* Iterate over the arguments and get the types of them in llvm */
        string arg_type = args[i]->getType();
        string arg_name = args[i]->getName();
        if (arg_type == "int") {
            arguments.push_back(Type::getInt32Ty(currentGlobals->Context));
        } else if (arg_type == "boolean") {
            arguments.push_back(Type::getInt1Ty(currentGlobals->Context));
        } else {
            currentGlobals->errors++;
            reportError::ErrorV("Arguments can only be int or boolean");
            return 0;
        }
        argTypes.emplace_back(arg_type);
        argNames.emplace_back(arg_name);
    }

    Type *returnType;
    /* Get the return Type */
    if (type == "int") {
        returnType = Type::getInt32Ty(currentGlobals->Context);
    } else if (type == "boolean") {
        returnType = Type::getInt1Ty(currentGlobals->Context);
    } else if (type == "void") {
        returnType = Type::getVoidTy(currentGlobals->Context);
    } else {
        currentGlobals->errors++;
        reportError::ErrorV("Invalid Return Type for " + name + ". Return Type can only be int or boolean or bool");
        return 0;
    }

    /* Get the function type and create a Function */
    FunctionType *FT = llvm::FunctionType::get(returnType, arguments, false);
    Function *F = llvm::Function::Create(FT, Function::ExternalLinkage, name, currentGlobals->TheModule);

    /* Iterate through arguments and set the Names for them */

    unsigned Idx = 0;
    for (Function::arg_iterator AI = F->arg_begin(); Idx != arg_size; ++AI, ++Idx) {
        AI->setName(argNames[Idx]);
    }

    /* Create a New block for this Function */
    BasicBlock *BB = BasicBlock::Create(currentGlobals->Context, "entry", F);
    currentGlobals->Builder->SetInsertPoint(BB);
    Idx = 0;

    /* Allocate memory for the arguments passed */
    for (auto &Arg : F->args()) {
        if (Idx == arg_size) { break; }
        AllocaInst *Alloca = CreateEntryBlockAlloca(F, argNames[Idx], argTypes[Idx], currentGlobals);
        currentGlobals->Builder->CreateStore(&Arg, Alloca);

        currentGlobals->NamedValues[argNames[Idx]] = Alloca;
        Idx++;
    }

    Value *RetVal = body->codegen(currentGlobals);
    if (RetVal) {
        /* make this the return value */
        if (type != "void")
            currentGlobals->Builder->CreateRet(RetVal);
        else
            currentGlobals->Builder->CreateRetVoid();
        /* Verify the function */
        verifyFunction(*F);
        return F;
    }
    /* Error Condition */
    F->eraseFromParent();
    return 0;
}