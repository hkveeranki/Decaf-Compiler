//
// Created by harry7 on 7/5/18.
//

#include "globals.h"

globals::globals() {
    this->Builder = new IRBuilder<>(Context);
    errors = 0;
    this->TheModule = new Module("Decaf compiler jit", Context);
}
