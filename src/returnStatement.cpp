/**
 * Implementation of \ref returnStatement class
 */

#include "returnStatement.h"

/**
 * Constructor for the class
 * @param expr expression that should be return
 */
returnStatement::returnStatement(class Expression *expr) {
    this->stype = stmtType::Return;
    this->ret = expr;
}

Value *returnStatement::generateCode(Constructs *compilerConstructs) {
    llvm::Value *V = nullptr;
    if (ret != nullptr) {
        /// Generate IR for expression to be returned
        V = ret->generateCode(compilerConstructs);
        if (ret->getEtype() == exprType::location) {
            /// Generate IR for returning it
            V = compilerConstructs->Builder->CreateLoad(V);
        }
        compilerConstructs->Builder->CreateRet(V);
        return V;
    }
    compilerConstructs->Builder->CreateRetVoid();
    return V;
}
