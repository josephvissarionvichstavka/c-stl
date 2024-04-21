//
// Created by father on 2024/4/21.
//

#include "assert.h"

#include <stdio.h>
#include <stdlib.h>
void _Assert(char * message){
    fputs(message,stderr);
    fputs(" -- assertion failed\n",stderr);
    abort();
}