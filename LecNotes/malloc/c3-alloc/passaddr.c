/*** passaddr.c ***/
#include <stdio.h>

void doubling(int* x, int* y) {
    (*x) = (*x) * 2;
    (*y) = (*y) * 2;
}

int main () {
    int x = 2, y = 10;
    printf("(%d,%d)\n", x, y);
    doubling(&x, &y);
    printf("(%d,%d)\n", x, y);
}
