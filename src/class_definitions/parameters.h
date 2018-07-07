/**
 * class to hold parameters passed during function calls namely method calls and callout calls
 */

#ifndef DECAF_COMPILER_PARAMETERS_H
#define DECAF_COMPILER_PARAMETERS_H

#include "astNode.h"
#include "constructs.h"
#include <vector>

class Parameters : public astNode {
private:
    /* list of parameters passed */
    std::vector<class Expression *> params;
public:
    Parameters() = default;

    void push_back(class Expression *);

    std::vector<class Expression *> getParams();
};

#endif
