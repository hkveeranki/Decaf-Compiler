/**
 * class to hold all the arguments given to the callout statement
 */

#ifndef DECAF_COMPILER_CALLOUTARGUMENTS_H
#define DECAF_COMPILER_CALLOUTARGUMENTS_H

#include <vector>
#include "astNode.h"
#include "calloutArgument.h"
#include "constructs.h"

class calloutArguments : public astNode {
private:
    /* list of arguments (\ref calloutArgument) given to the callout statement */
    std::vector<class calloutArgument *> args_list;
public:
    /**
     * Default constructor
     */
    calloutArguments() = default;

    void push_back(class calloutArgument *);

    std::vector<class calloutArgument *> getArgsList();
};


#endif
