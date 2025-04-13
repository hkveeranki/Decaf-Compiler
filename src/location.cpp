/**
 * Implementation of \ref Location class */

#include "location.h"
#include "utilities.h"

/**
 * Constructor for the class when location is an array
 * @param variable_name name of the variable
 * @param index index of the array which is the current location
 */
Location::Location(string variable_name, class Expression *index) {
    this->var = std::move(variable_name);
    this->location_type = locationType::array;
    this->array_index = index;
    this->etype = exprType::location;
}

/**
 * Constructor for the class when location is a variable
 * @param variable_name name of the variable
 */
Location::Location(string variable_name) {
    this->var = std::move(variable_name);
    this->location_type = locationType::variable;
    this->array_index = nullptr;
    this->etype = exprType::location;
}

/**
 * Return name of the variable/array in the location
 * @return string which contains name of the variable
 */
string Location::getVar() {
    return var;
}

Type* Location::getValueType(Value* val) {
    Type* value_type; 
    if (location_type == locationType::variable) {
        AllocaInst* alloca = dyn_cast<AllocaInst>(val);
        if (alloca == nullptr) {
            GlobalVariable* global = dyn_cast<GlobalVariable>(val);
            value_type = global->getValueType();
        }
        else{
            value_type = alloca->getAllocatedType();
        }
    } else {
        GetElementPtrInst* gep = dyn_cast<GetElementPtrInst>(val);
        value_type = gep->getSourceElementType();
    }
    return value_type;
}

Value *Location::generateCode(Constructs *compilerConstructs) {
    /* Try to get the value of the variable */
    Type* value_type;
    Value *V = compilerConstructs->NamedValues[var];
    if (V == nullptr) {
        V = compilerConstructs->TheModule->getNamedGlobal(var);
        if (V == nullptr) {
            compilerConstructs->errors++;
            return reportError("Unknown Variable name " + var);
        }
        value_type = dyn_cast<GlobalVariable>(V)->getValueType();
    } else{
        value_type = dyn_cast<AllocaInst>(V)->getAllocatedType();
    }
    
    /* If location is variable return the code generated */
    if (this->location_type == locationType::variable) {
        return V;
    }
    /* Check if we have an index for array */
    if (this->array_index == nullptr) {
        return invalidArrayIndex(compilerConstructs);
    }
    /* Generate the code for index of the array */
    Value *index = array_index->generateCode(compilerConstructs);
    if (array_index->getEtype() == exprType::location) {
        Type* value_type = dynamic_cast<Location*>(array_index)->getValueType(index);
        index = compilerConstructs->Builder->CreateLoad(value_type, index);
    }
    /* If index is invalid then report error */
    if (index == nullptr) {
        return invalidArrayIndex(compilerConstructs);
    }
    /* Generate the code required for accessing the array at the given index */
    vector<Value *> array_index;
    // array_index.push_back(compilerConstructs->Builder->getInt32(0));
    array_index.push_back(index);
    V = compilerConstructs->Builder->CreateGEP(value_type->getArrayElementType(), V, array_index, var + "_Index");
    return V;
}

Value *Location::invalidArrayIndex(Constructs *compilerConstructs) {
    compilerConstructs->errors++;
    return reportError("Invalid array index");
}
