#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
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
    return 0;
}

void merge(void* array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*), int l, int m, int r){
    printArray(array, len);
    int i = 0, j = 0, k = 0;
    int n1 = m - l + 1;
    int n2 = r-m;
    // printf("\n\nl:%d, r:%d m:%d\n\n", l, r, m);
    void* arr1 = malloc(elem_sz*n1);
    void* arr2 = malloc(elem_sz*n2);

    for(i = 0; i < n1; i++){
        memcpy(arr1+i*elem_sz, array+((l+i)*elem_sz), elem_sz);

    }  
    for(j = 0; j < n2; j++){
        memcpy(arr2+j*elem_sz, array+((m+1+j)*elem_sz), elem_sz);

    }
    printf("merging: ");
    printArray(arr1, n1);
    printf("and ");
    printArray(arr2, n2);
    printf("\n");

    i = 0; j = 0; k = 0;
    while(i < n1 && j < n2){
        if(comp(arr1+i*elem_sz, arr2+j*elem_sz) != 1){
            memcpy(array+((k+l)*elem_sz), arr1+i*elem_sz, elem_sz);
            i++;
        }else{
            memcpy(array+((k+l)*elem_sz), arr2+j*elem_sz, elem_sz);
            j++; 
        }

        k++;
    }

    while(i < n1){
        memcpy(array+(k+l)*elem_sz, arr1+i*elem_sz, elem_sz);
        i++;
        k++;
    }

    while(j < n2){
        memcpy(array+((k+l)*elem_sz), arr2+j*elem_sz, elem_sz);
        j++;       
        k++;
    }
    printf("final array: ");
    for(int b = 0; b < k; b++){
       printf("%d ",*(int*) (array+b*elem_sz));
    }
    printf("\n");


    free(arr1);
    free(arr2);
}

void mergeH(void* array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*), int l, int r){
        printArray(array, len);

    if(l < r){
        int m = l + (r - l) / 2;
        mergeH(array, m-l, elem_sz, comp, l, m);
        mergeH(array, r-(m+1), elem_sz, comp, m+1, r);
        merge(array, len, elem_sz, comp, l, m, r);
    }
}
/* Main sorting algorithm you need to implement */
void mergesort(void*  array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*)){
    mergeH(array, len, elem_sz, comp, 0, len);
}


void printArray(int* array, int len){
    printf("\n Array: ");
    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
}

int main(int argc, char* argv[]){
    int* bal = (double*) malloc(sizeof(double)*1024);
    bal[0] = 613;
    bal[1] = 8281;
    bal[2] = 23;
    bal[3] = 1;
    bal[4] = 6123;
    bal[5] = 2134;
    bal[6] = 1929;
    printArray(bal, 7);
    mergesort(bal, 6, sizeof(int), int_cmp);
    printArray(bal, 7);    
    free(bal);
    return 0;
}
