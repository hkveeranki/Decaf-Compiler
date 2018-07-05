//
// Created by harry7 on 7/4/18.
//

#include "stringLiteral.h"
#include "utilities.h"
#include "common.h"

#include <string>

stringLiteral::stringLiteral(std::string val) {
    val = val.substr(1, val.length() - 2);
    val = replace_newline(val);
    this->value = val;
    this->ltype = literalType::String;
}

Value *stringLiteral::codegen(globals *currentGlobals) {
    return currentGlobals->Builder->CreateGlobalStringPtr(value);
}