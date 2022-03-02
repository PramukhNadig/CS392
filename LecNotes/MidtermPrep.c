#include <stdio.h>
#include <stdlib.h>




int main(int argc, char **argv){
    FILE* file = fopen(argv[1], "r");
    string line;
    int size = 0;
    double curr;
    array = (double*) realloc(array, size * sizeof(double, ))
    while(fscanf(file, "%lf", &curr))){
        size++;
    }

    rewind(file);
    double *array = (double*) malloc(size * sizeof(double));
    size = 0;
    while(fscanf(file, "%lf", &curr))){
        array[size++] = curr;
    }


    for(int i = 0; i < size; i++){
        printf("%lf:0x%x  ", array[i], &array[i]);
    }
    return 0;
}