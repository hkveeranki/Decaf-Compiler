//
// Created by harry7 on 7/4/18.
//

#include "unaryExpression.h"

#include "globals.h"

using namespace std;

unaryExpression::unaryExpression(string opr, class Expression *expr) {
    this->opr = opr;
    this->body = expr;
    this->etype = exprType::Unexpr;
}

Value *unaryExpression::generateCode(globals *currentGlobals) {
    Value *v = body->generateCode(currentGlobals);
    if (body->getEtype() == exprType::location) {
        v = currentGlobals->Builder->CreateLoad(v);
    }
    if (opr == "-") {
        return currentGlobals->Builder->CreateNeg(v, "negtmp");
    } else if (opr == "!") {
        return currentGlobals->Builder->CreateNot(v, "nottmp");
    }
}
