//
// Created by harry7 on 7/4/18.
//
#include <utility>


#include "binExpr.h"
#include "common.h"
#include "globals.h"

binExpr::binExpr(class Expr *lhs, string opr, class Expr *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
    this->opr = std::move(opr);
    this->etype = exprType::binary;
}

Value *binExpr::codegen(globals *currentGlobals) {
    Value *left = lhs->codegen(currentGlobals);
    Value *right = rhs->codegen(currentGlobals);
    if (lhs->getEtype() == exprType::location) {
        left = currentGlobals->Builder->CreateLoad(left);
    }
    if (rhs->getEtype() == exprType::location) {
        right = currentGlobals->Builder->CreateLoad(right);
    }
    if (left == 0) {
        currentGlobals->errors++;
        return reportError::ErrorV("Error in left operand of " + opr);
    } else if (right == 0) {
        currentGlobals->errors++;
        return reportError::ErrorV("Error in right operand of " + opr);
    }
    Value *v = nullptr;
    if (opr == "+") {
        v = currentGlobals->Builder->CreateAdd(left, right, "addtmp");
    } else if (opr == "-") {
        v = currentGlobals->Builder->CreateSub(left, right, "subtmp");
    } else if (opr == "*") {
        v = currentGlobals->Builder->CreateMul(left, right, "multmp");
    } else if (opr == "/") {
        v = currentGlobals->Builder->CreateUDiv(left, right, "divtmp");
    } else if (opr == "%") {
        v = currentGlobals->Builder->CreateURem(left, right, "modtmp");
    } else if (opr == "<") {
        v = currentGlobals->Builder->CreateICmpULT(left, right, "ltcomparetmp");
    } else if (opr == ">") {
        v = currentGlobals->Builder->CreateICmpUGT(left, right, "gtcomparetmp");
    } else if (opr == "<=") {
        v = currentGlobals->Builder->CreateICmpULE(left, right, "lecomparetmp");
    } else if (opr == ">=") {
        v = currentGlobals->Builder->CreateICmpUGE(left, right, "gecomparetmp");
    } else if (opr == "==") {
        v = currentGlobals->Builder->CreateICmpEQ(left, right, "equalcomparetmp");
    } else if (opr == "!=") {
        v = currentGlobals->Builder->CreateICmpNE(left, right, "notequalcomparetmp");
    }
    return v;
}