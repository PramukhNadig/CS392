#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

int main(int argc, char **argv){
    int* vector = (void*) malloc(sizeof(int) * 1024);

    int i = 12;
    int j = 15;
    *vector = i;
    *(vector+1) = j;

    assert(int_cmp(&i,&j) == -1);
    assert(int_cmp(&j,&i) == 1);
    assert(int_cmp(&i,&i) == 0);
    assert(*vector == 12);
    assert(*(vector+1) == j);

}