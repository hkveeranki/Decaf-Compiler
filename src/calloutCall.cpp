//
// Created by harry7 on 7/4/18.
//

#include "calloutCall.h"
#include "calloutArguments.h"
#include "globals.h"
#include "utilities.h"
#include <vector>

calloutCall::calloutCall(std::string method_name, class calloutArguments *args) {
    this->method_name = method_name.substr(1, method_name.length() - 2);
    this->args = args;
}

Value *calloutCall::generateCode(globals *currentGlobals) {

    std::vector<llvm::Type *> argTypes;
    std::vector<Value *> Args;
    std::vector<class calloutArgument *> args_list = args->getArgsList();
    for (int i = 0; i < args_list.size(); i++) {
        Value *tmp = args_list[i]->generateCode(currentGlobals);
        if (tmp == 0) {
            // Some thing is wrong with the args passed
            return 0;
        }
        Args.push_back(tmp);
        argTypes.push_back(tmp->getType());
    }

    llvm::ArrayRef<llvm::Type *> argsRef(argTypes);
    llvm::ArrayRef<llvm::Value *> funcargs(Args);
    llvm::FunctionType *FType = FunctionType::get(Type::getInt32Ty(currentGlobals->Context), argsRef, false);
    Constant *func = currentGlobals->TheModule->getOrInsertFunction(method_name, FType);
    if (!func) {
        return reportError("Error in inbuilt function. Unknown Function name " + method_name);
    }
    Value *v = currentGlobals->Builder->CreateCall(func, funcargs);
    return v;
}

