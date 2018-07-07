/**
 * Implementation of \ref Assignment\ref  class
 */

#include <utility>
#include "assignment.h"
#include "utilities.h"

/**
 * Default constructor
 * @param location location to which the assignment is done
 * @param assignmentOperator name of the operator with which assignment is done can be "=" "+=" or "-="
 * @param expression expression which has been assigned
 */
Assignment::Assignment(class Location *location, string assignmentOperator, class Expression *expression) {
    this->stype = stmtType::NonReturn;
    this->loc = location;
    this->opr = std::move(assignmentOperator);
    this->expr = expression;
}

Value *Assignment::generateCode(Constructs *compilerConstructs) {

    Value *cur = compilerConstructs->NamedValues[loc->getVar()];
    if (cur == nullptr) {
        cur = compilerConstructs->TheModule->getGlobalVariable(loc->getVar());
    }
    if (cur == nullptr) {
        compilerConstructs->errors++;
        return reportError("Unknown Variable Name");
    }

    Value *val = expr->generateCode(compilerConstructs);
    if (expr->getEtype() == exprType::location) {
        val = compilerConstructs->Builder->CreateLoad(val);
    }

    Value *lhs = loc->generateCode(compilerConstructs);
    cur = compilerConstructs->Builder->CreateLoad(lhs);

    if (val == nullptr) {
        compilerConstructs->errors++;
        return reportError("Error in right hand side of the Assignment");
    }
    if (opr == "+=") {
        val = compilerConstructs->Builder->CreateAdd(cur, val, "addEqualToTmp");
    } else if (opr == "-=") {
        val = compilerConstructs->Builder->CreateSub(cur, val, "subEqualToTmp");
    }
    return compilerConstructs->Builder->CreateStore(val, lhs);
}
