/**
 * Implementation of \ref methodDeclaration class
 */

#include <llvm/IR/Verifier.h>
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
        Idx++;
    }

    Value *RetVal = body->generateCode(compilerConstructs);
    if (RetVal) {
        /* make this the return value */
        if (return_type != "void")
            compilerConstructs->Builder->CreateRet(RetVal);
        else
            compilerConstructs->Builder->CreateRetVoid();
        /* Verify the function */
        verifyFunction(*F);
        compilerConstructs->TheFPM->run(*F);
        return F;
    }
    /* In case of errors remove the function */
    F->eraseFromParent();
    return nullptr;
}