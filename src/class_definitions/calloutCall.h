/**
 * Class to deal with the callout statement present in the code
 */

#ifndef DECAF_COMPILER_CALLOUTCALL_H
#define DECAF_COMPILER_CALLOUTCALL_H

#include <string>
#include "functionCall.h"
#include "constructs.h"

class calloutCall : public functionCall {
private:
    /* Args passed to callout call */
    class calloutArguments *args;

public:
    calloutCall(std::string, class calloutArguments *);

    Value *generateCode(Constructs *compilerConstructs);
};


#endif
