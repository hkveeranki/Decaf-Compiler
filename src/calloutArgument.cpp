//
// Created by harry7 on 7/4/18.
//

#include "calloutArgument.h"
#include "globals.h"
#include "stringLiteral.h"
#include "utilities.h"
#include <utility>

calloutArgument::calloutArgument(class Expression *arg) {
    this->expr = arg;
}

calloutArgument::calloutArgument(std::string literal) {
    class stringLiteral *tmp = new stringLiteral(std::move(literal));
    this->expr = tmp;
}


Value *calloutArgument::generateCode(globals *currentGlobals) {
    if (expr == nullptr) {
        currentGlobals->errors++;
        return reportError("Invalid Callout Arg");
    }
    Value *v = expr->generateCode(currentGlobals);
    if (expr->getEtype() == exprType::location) {
        v = currentGlobals->Builder->CreateLoad(v);
    }
    return v;
}