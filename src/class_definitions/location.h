/*
 * class to hold locations ( variables, array locations etc ) in the code
 */

#ifndef DECAF_COMPILER_LOCATION_H
#define DECAF_COMPILER_LOCATION_H


#include "expression.h"
#include "constructs.h"
#include <string>

using namespace std;

enum locationType {
    array = 1, variable = 2
};

class Location : public Expression {
private:
    /* name used in location */
    string var;
    /* Array or normal */
    locationType location_type;

    /* if it is array then we have the address */
    class Expression *array_index;

    /* If the index provided for the array is invalid report error */
    Value *invalidArrayIndex(Constructs *compilerConstructs);

public:
    Location(string, class Expression *);

    explicit Location(string);

    string getVar();

    Type* getValueType(Value* val);
    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
