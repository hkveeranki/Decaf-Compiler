/**
 * Implementation of the \ref  Method class
 */
#include <utility>
#include <string>

#include "constructs.h"
#include "methodCall.h"
#include "parameters.h"
#include "utilities.h"

/**
 * Constructor for the class
 * @param method_name name of the method that is called
 * @param params parameters to be passed to the function
 */

methodCall::methodCall(std::string method_name, class Parameters *params) {
    this->method_name = std::move(method_name);
    this->parameters = params;
}

Value *methodCall::generateCode(Constructs *compilerConstructs) {
    /* Get reference to the function that is to be called */
    Function *calle = compilerConstructs->TheModule->getFunction(method_name);
    if (calle == nullptr) {
        compilerConstructs->errors++;
        return reportError("Unknown Function name" + method_name);
    }
    /* Check if required number of parameters are passed */
    vector<class Expression *> args_list = parameters->getParams();
    if (calle->arg_size() != args_list.size()) {
        compilerConstructs->errors++;
        return reportError("Incorrect Number of Parameters Passed");
    }
    /// Generate the code for the arguments
    vector<Value *> Args;
    for (auto &arg : args_list) {
        Value *argVal = arg->generateCode(compilerConstructs);
        if (arg->getEtype() == exprType::location) {
            argVal = compilerConstructs->Builder->CreateLoad(argVal);
        }
        if (argVal == nullptr) {
            compilerConstructs->errors++;
            reportError("Argument is not valid");
            return nullptr;
        }
        Args.push_back(argVal);
    }
    // Reverse the order of arguments as the parser parses in the reverse order
    std::reverse(Args.begin(), Args.end());
    // Generate the code for the function call
    Value *v = compilerConstructs->Builder->CreateCall(calle, Args);
    return v;
}