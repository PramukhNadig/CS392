#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"


int main(int argc, char **argv){
    FILE *fp;
    fp = fopen("test.txt", "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int* vector = (void*) malloc(sizeof(int) * 1024);

    int i = 12;
    int j = 15;
    double k = 1.0;
    double l = 2.0;
    *vector = i;
    *(vector+1) = j;

    assert(int_cmp(&i,&j) == -1);
    assert(int_cmp(&j,&i) == 1);
    assert(int_cmp(&i,&i) == 0);
    assert(dbl_cmp(&k, &l) == -1);
    assert(dbl_cmp(&k, &k) == 0);
    assert(dbl_cmp(&l, &k) == 1);
    assert(*vector == 12);
    assert(*(vector+1) == j);

}