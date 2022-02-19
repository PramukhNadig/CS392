/*** memleak2.c ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void create_array (int* vector) {
    vector = (int*) malloc(sizeof(int) * 10);
}

int main () {
    /*int* vector;
    create_array(vector);
    for (int i = 0; i < 5; i ++) printf("%d\n", vector[i]);
    free(vector);
*/
    printf("%d\n", strlen("hello"));

    return 0;
}
