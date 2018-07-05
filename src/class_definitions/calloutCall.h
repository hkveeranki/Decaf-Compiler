//
// Created by harry7 on 7/4/18.
//

#ifndef DECAF_COMPILER_CALLOUTCALL_H
#define DECAF_COMPILER_CALLOUTCALL_H

#include <string>
#include "methodCall.h"
#include "globals.h"

class calloutCall : public methodCall {
private:
    class calloutArguments *args; /* Args passed to callout call */
public:
    calloutCall(std::string, class calloutArguments *);

    Value *generateCode(globals *currentGlobals);
};


#endif
