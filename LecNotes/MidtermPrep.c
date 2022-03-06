#include <stdio.h>
#include <stdlib.h>




int main(int argc, char **argv){
    FILE* file = fopen(argv[1], "r");
    char* line;
    int size = 0;
    double curr;
    
    while(fscanf(file, "%lf", &curr) != EOF){
        size++;
    }

    rewind(file);
    double *array = (double*) malloc(size * sizeof(double));
    size = 0;
    while(fscanf(file, "%lf", &curr) != EOF){
        array[size++] = curr;
    }


    for(int i = 0; i < size; i++){
        double* arr = &array[i];
        unsigned char* x = (unsigned char*) &arr;
        printf("%x\n", &arr);
        printf("%lf : ", array[i]);
        for(int j = 0; j < sizeof(double); j++){
            printf("0x%x ", x[j]);
        }
        puts("\n");
    }
    FILE* fp = fopen(argv[2], "w+");
    for(int i = 0; i < size; i++){
        fprintf(fp, "%f\n", array[i]);
    }

    free(array);
    fclose(fp);
    fclose(file);
    return 0;
}

