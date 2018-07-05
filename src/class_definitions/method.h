//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_METHOD_H
#define DECAF_COMPILER_METHOD_H


#include "methodCall.h"
#include "globals.h"
#include <string>

class Method : public methodCall {
private:
    class Parameters *parameters;/* Parameters passed to method call */
public:
    Method(std::string, class Parameters *);

    Value *generateCode(globals *currentGlobals);
};


#endif
