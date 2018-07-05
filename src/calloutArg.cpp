//
// Created by harry7 on 7/4/18.
//

#include "calloutArg.h"
#include <utility>
#include "common.h"
#include "stringLiteral.h"
#include "globals.h"

calloutArg::calloutArg(class Expr *arg) {
    this->expr = arg;
}

calloutArg::calloutArg(std::string literal) {
    class stringLiteral *tmp = new stringLiteral(std::move(literal));
    this->expr = tmp;
}


Value *calloutArg::codegen(globals *currentGlobals) {
    if (expr == nullptr) {
        currentGlobals->errors++;
        return reportError::ErrorV("Invalid Callout Arg");
    }
    Value *v = expr->codegen(currentGlobals);
    if (expr->getEtype() == exprType::location) {
        v = currentGlobals->Builder->CreateLoad(v);
    }
    return v;
}