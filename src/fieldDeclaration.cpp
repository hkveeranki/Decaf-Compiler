/**
 * Implementation of \ref fieldDeclaration class
 */
#include "fieldDeclaration.h"

/**
 * Constructor for the class
 * @param dataType data type in the declaration i.e the data type for all the variables listed
 * @param variables variables that are listed in the declaration
 */
fieldDeclaration::fieldDeclaration(string dataType, class Variables *variables) {
    this->dataType = dataType;
    this->var_list = variables->getVarsList();
}

Value *fieldDeclaration::generateCode(Constructs *compilerConstructs) {
    llvm::Type *ty = nullptr;
    /* Get the type reference */
    if (dataType == "int") {
        ty = Type::getInt32Ty(compilerConstructs->Context);
    } else if (dataType == "boolean") {
        ty = Type::getInt1Ty(compilerConstructs->Context);
    }
    for (auto var : var_list) {
        /* Allocate one location of global variable for all */
        if (var->isArray()) {
            ArrayType *arrType = ArrayType::get(ty, var->getLength());
            GlobalVariable *gv = new GlobalVariable(*(compilerConstructs->TheModule), arrType, false,
                                                    GlobalValue::ExternalLinkage, nullptr,
                                                    var->getName());
            gv->setInitializer(ConstantAggregateZero::get(arrType));
        } else {
            GlobalVariable *gv = new GlobalVariable(*(compilerConstructs->TheModule), ty, false,
                                                    GlobalValue::ExternalLinkage, nullptr,
                                                    var->getName());
            gv->setInitializer(Constant::getNullValue(ty));
        }
    }
    Value *v = ConstantInt::get(compilerConstructs->Context, APInt(32, 1));
    return v;
}