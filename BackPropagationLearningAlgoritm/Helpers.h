#ifndef _HELPERS_H_
#define _HELPERS_H_

#include <stdlib.h>

#define ALLOC_OBJ(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define ALLOC_ARRAY(TYPE, LENGTH) (TYPE*)malloc(sizeof(TYPE) * LENGTH)
//Returns a random real number which lies in a range [0:1];
#define NEXT_DOUBLE() ((double)rand() / (double)RAND_MAX)

#endif