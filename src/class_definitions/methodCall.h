/**
 * class to handle function calls to the methods of the form functionName() in the code
 */

#ifndef DECAF_COMPILER_METHODCALL_H
#define DECAF_COMPILER_METHODCALL_H


#include "functionCall.h"
#include "constructs.h"
#include <string>

class methodCall : public functionCall {
private:
    /* Parameters passed to method call */
    class Parameters *parameters;

public:
    methodCall(std::string, class Parameters *);

    Value *generateCode(Constructs *compilerConstructs) override;
};


#endif
