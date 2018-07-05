//
// Created by harry7 on 7/4/18.
//


#include "fieldDeclaration.h"

fieldDeclaration::fieldDeclaration(string dataType, class Variables *vars) {
    this->dataType = dataType;
    this->var_list = vars->getVarsList();
    for (int i = 0; i < var_list.size(); i++) {
        var_list[i]->setDataType(dataType);
    }
}

vector<class Variable *> fieldDeclaration::getVarsList() {
    return var_list;
}

Value *fieldDeclaration::generateCode(globals *currentGlobals) {
    for (int i = 0; i < var_list.size(); i++) {
        /* Allocate one location of global variable for all */
        class Variable *var = var_list[i];
        llvm::Type *ty = nullptr;
        if (dataType == "int") {
            ty = Type::getInt32Ty(currentGlobals->Context);
        } else if (dataType == "boolean") {
            ty = Type::getInt1Ty(currentGlobals->Context);
        }
        if (var->isArray()) {
            ArrayType *arrType = ArrayType::get(ty, var->getLength());
            PointerType *PointerTy_1 = PointerType::get(ArrayType::get(ty, var->getLength()), 0);
            GlobalVariable *gv = new GlobalVariable(*(currentGlobals->TheModule), arrType, false,
                                                    GlobalValue::ExternalLinkage, 0,
                                                    var->getName());
            gv->setInitializer(ConstantAggregateZero::get(arrType));
        } else {
            PointerType *ptrTy = PointerType::get(ty, 0);
            GlobalVariable *gv = new GlobalVariable(*(currentGlobals->TheModule), ptrTy, false,
                                                    GlobalValue::ExternalLinkage, 0,
                                                    var->getName());
        }
    }
    Value *v = ConstantInt::get(currentGlobals->Context, APInt(32, 1));
    return v;
}