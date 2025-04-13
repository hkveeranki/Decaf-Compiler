/**
 * Implementation of \ref returnStatement class
 */

#include "returnStatement.h"
#include "location.h"
/**
 * Constructor for the class
 * @param expr expression that should be return
 */
returnStatement::returnStatement(class Expression *expr) {
    this->mhas_return = true;
    this->mhas_break = false;
    this->mhas_continue = false;
    this->ret = expr;
}

Value *returnStatement::generateCode(Constructs *compilerConstructs) {
    llvm::Value *V = nullptr;
    if (ret != nullptr) {
        /// Generate IR for expression to be returned
        V = ret->generateCode(compilerConstructs);
        if (ret->getEtype() == exprType::location) {
            /// Generate IR for returning it
            Location *loc = static_cast<Location *>(ret);
            V = compilerConstructs->Builder->CreateLoad(loc->getValueType(V), V);
        }
        compilerConstructs->Builder->CreateRet(V);
        return V;
    }
    compilerConstructs->Builder->CreateRetVoid();
    return V;
}
