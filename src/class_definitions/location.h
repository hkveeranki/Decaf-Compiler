//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_LOCATION_H
#define DECAF_COMPILER_LOCATION_H


#include "expression.h"
#include "globals.h"
#include <string>

using namespace std;

class Location : public Expression {
private:
    string var; /* name used in location */
    string location_type; /* Array or normal */
    class Expression *expr; /* if it is array then we have the address */
public:
    Location(string, string, class Expression *);

    Location(string, string);

    string getVar();/* returns the var name */
    bool is_array(); /* tells if its array or not */
    class Expression *getExpr();

    Value *generateCode(globals *currentGlobals);
};


#endif
