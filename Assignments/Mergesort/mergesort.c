#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"


/* Functions to compare a and b */
int int_cmp(const void* a, const void* b){
    int* c = ((int*) a);
    int* d = ((int*) b);

    if(*c > *d){
        return 1;
    }else if (*d > *c){
        return -1;
    }
    return 0;

}
int dbl_cmp(const void* a, const void* b){
    double* c = ((double*) a);
    double* d = ((double*) b);

    if(*c > *d){
        return 1;
    }else if (*d > *c){
        return -1;
    }
    return 0;}

/* Main sorting algorithm you need to implement */
void mergesort(void*  array,
               size_t len,
               size_t elem_sz,
               int (*comp)(const void*, const void*));

