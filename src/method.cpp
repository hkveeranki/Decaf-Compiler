//
// Created by harry7 on 7/4/18.
//
#include <utility>
#include <string>

#include "globals.h"
#include "method.h"
#include "parameters.h"
#include "utilities.h"

Method::Method(std::string method_name, class Parameters *params) {
    this->method_name = std::move(method_name);
    this->parameters = params;
}

Value *Method::generateCode(globals *currentGlobals) {
    Function *calle = currentGlobals->TheModule->getFunction(method_name);
    if (calle == 0) {
        currentGlobals->errors++;
        return reportError("Unknown Function name" + method_name);
    }
    vector<class Expression *> args_list = parameters->getExprList();
    if (calle->arg_size() != args_list.size()) {
        currentGlobals->errors++;
        return reportError("Incorrect Number of Parameters Passed");
    }
    vector<Value *> Args;
    for (int i = 0; i < args_list.size(); i++) {
        Value *argval = args_list[i]->generateCode(currentGlobals);
        if (args_list[i]->getEtype() == exprType::location) {
            argval = currentGlobals->Builder->CreateLoad(argval);
        }
        if (argval == 0) {
            // Some thing is wrong with the args passed
            return 0;
        }
        Args.push_back(argval);
    }
    Value *v = currentGlobals->Builder->CreateCall(calle, Args);
    return v;
}
