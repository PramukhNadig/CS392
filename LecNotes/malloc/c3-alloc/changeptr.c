/*** changeptr.c ***/
#include <stdio.h>

void increment_ptr (int* p) {
    p ++;
}

int main () {
    int vector[5] = {10,20,30,40,50};
    int* ptr = vector;
    printf("%d\n", *ptr);
    increment_ptr(ptr);
    printf("%d\n", *ptr);
    return 0;
}
