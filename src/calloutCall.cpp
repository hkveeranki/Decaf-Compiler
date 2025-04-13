/**
 * Implementation of the \ref  calloutCall class
 */
#include "calloutCall.h"
#include "calloutArguments.h"
#include "utilities.h"

/**
 * Constructor for the calloutCall class
 * @param method_name name of the function to be called
 * @param args list of arguments for the function
 */
calloutCall::calloutCall(std::string method_name, class calloutArguments *args) {
    this->method_name = method_name.substr(1, method_name.length() - 2);
    this->args = args;
}

Value *calloutCall::generateCode(Constructs *compilerConstructs) {

    std::vector<llvm::Type *> argTypes;
    std::vector<Value *> Args;
    std::vector<class calloutArgument *> args_list = args->getArgsList();
    /**
     * Iterate through the arguments and generate the code required for each one of them
     */
    for (auto &i : args_list) {
        Value *tmp = i->generateCode(compilerConstructs);
        if (tmp == nullptr) {
            return nullptr;
        }
        Args.push_back(tmp);
        argTypes.push_back(tmp->getType());
    }
    /* Generate the code for the function execution */
    llvm::ArrayRef<llvm::Type *> argsRef(argTypes);
    llvm::ArrayRef<llvm::Value *> funcargs(Args);
    llvm::FunctionType *FType = FunctionType::get(Type::getInt32Ty(compilerConstructs->Context), argsRef, false);
    llvm::FunctionCallee func = compilerConstructs->TheModule->getOrInsertFunction(method_name, FType);
    if (!func) {
        return reportError("Error in inbuilt function. Unknown Function name " + method_name);
    }
    Value *v = compilerConstructs->Builder->CreateCall(func, funcargs);
    return v;
}

