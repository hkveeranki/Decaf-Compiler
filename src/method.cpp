//
// Created by harry7 on 7/4/18.
//
#include <utility>
#include "common.h"
#include "method.h"
#include "params.h"
#include "globals.h"

Method::Method(string method_name, class Params *params) {
    this->method_name = std::move(method_name);
    this->params = params;
}

Value *Method::codegen(globals *currentGlobals) {
    Function *calle = currentGlobals->TheModule->getFunction(method_name);
    if (calle == 0) {
        currentGlobals->errors++;
        return reportError::ErrorV("Unknown Function name" + method_name);
    }
    vector<class Expr *> args_list = params->getExprList();
    if (calle->arg_size() != args_list.size()) {
        currentGlobals->errors++;
        return reportError::ErrorV("Incorrect Number of Parameters Passed");
    }
    vector<Value *> Args;
    for (int i = 0; i < args_list.size(); i++) {
        Value *argval = args_list[i]->codegen(currentGlobals);
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
