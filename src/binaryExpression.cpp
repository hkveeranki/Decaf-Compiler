/**
 * Implementation of \ref binaryExpression class */
#include <utility>


#include "binaryExpression.h"
#include "utilities.h"

/**
 * Constructor for binaryExpression class
 * @param lhs left hand side of the expression
 * @param opr operator present in the expression can be
 *            arithmetic operators like "+", "-", "*", "/", "%" or
 *            comparing operators like "<", ">", "<=", ">=", "==", "!="
 * @param rhs right hand side of the expression
 */
binaryExpression::binaryExpression(class Expression *lhs, string opr, class Expression *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
    this->opr = std::move(opr);
    this->etype = exprType::binary;
}

Value *binaryExpression::generateCode(Constructs *compilerConstructs) {
    Value *left = lhs->generateCode(compilerConstructs);
    Value *right = rhs->generateCode(compilerConstructs);
    if (lhs->getEtype() == exprType::location) {
        left = compilerConstructs->Builder->CreateLoad(left);
    }
    if (rhs->getEtype() == exprType::location) {
        right = compilerConstructs->Builder->CreateLoad(right);
    }
    if (left == 0) {
        compilerConstructs->errors++;
        return reportError("Error in left operand of " + opr);
    } else if (right == 0) {
        compilerConstructs->errors++;
        return reportError("Error in right operand of " + opr);
    }
    Value *v = nullptr;
    if (opr == "+") {
        v = compilerConstructs->Builder->CreateAdd(left, right, "addtmp");
    } else if (opr == "-") {
        v = compilerConstructs->Builder->CreateSub(left, right, "subtmp");
    } else if (opr == "*") {
        v = compilerConstructs->Builder->CreateMul(left, right, "multmp");
    } else if (opr == "/") {
        v = compilerConstructs->Builder->CreateSDiv(left, right, "divtmp");
    } else if (opr == "%") {
        v = compilerConstructs->Builder->CreateSRem(left, right, "modtmp");
    } else if (opr == "<") {
        v = compilerConstructs->Builder->CreateICmpSLT(left, right, "ltcomparetmp");
    } else if (opr == ">") {
        v = compilerConstructs->Builder->CreateICmpSGT(left, right, "gtcomparetmp");
    } else if (opr == "<=") {
        v = compilerConstructs->Builder->CreateICmpSLE(left, right, "lecomparetmp");
    } else if (opr == ">=") {
        v = compilerConstructs->Builder->CreateICmpSGE(left, right, "gecomparetmp");
    } else if (opr == "==") {
        v = compilerConstructs->Builder->CreateICmpEQ(left, right, "equalcomparetmp");
    } else if (opr == "!=") {
        v = compilerConstructs->Builder->CreateICmpNE(left, right, "notequalcomparetmp");
    }
    return v;
}