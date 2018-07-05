//
// Created by harry7 on 7/4/18.
//

#include <utility>
#include "assignment.h"
#include "utilities.h"
#include "globals.h"

Assignment::Assignment(class Location *loc, string oper, class Expression *expr) {
    this->stype = stmtType::NonReturn;
    this->loc = loc;
    this->opr = std::move(oper);
    this->expr = expr;
}

Value *Assignment::generateCode(globals *currentGlobals) {

    Value *cur = currentGlobals->NamedValues[loc->getVar()];
    if (cur == 0) {
        cur = currentGlobals->TheModule->getGlobalVariable(loc->getVar());
    }
    if (cur == 0) {
        currentGlobals->errors++;
        return reportError("Unknown Variable Name");
    }

    Value *val = expr->generateCode(currentGlobals);
    if (expr->getEtype() == exprType::location) {
        val = currentGlobals->Builder->CreateLoad(val);
    }

    Value *lhs = loc->generateCode(currentGlobals);
    cur = currentGlobals->Builder->CreateLoad(lhs);

    if (val == nullptr) {
        currentGlobals->errors++;
        return reportError("Error in right hand side of the Assignment");
    }
    if (opr == "+=") {
        val = currentGlobals->Builder->CreateAdd(cur, val, "addEqualToTmp");
    } else if (opr == "-=") {
        val = currentGlobals->Builder->CreateSub(cur, val, "subEqualToTmp");
    }
    return currentGlobals->Builder->CreateStore(val, lhs);
}
