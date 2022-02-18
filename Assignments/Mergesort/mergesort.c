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
    int i = 0, j = 0, k = 0;
    int n1 = m - l + 1;
    int n2 = r-m;
    void* arr1 = (void*) malloc(elem_sz*n1);
    void* arr2 = (void*) malloc(elem_sz*n2);

    printf("arr1: ");
    for(i = 0; i < n1; i++){
        memcpy(arr1+i*elem_sz, array+((l+i)*elem_sz), elem_sz);
            printf("%d ", *(int*) (array+((l+i)*elem_sz)));

    }  
    printf("arr2: ");
    for(j = 0; j < n2; j++){
        memcpy(arr2+j*elem_sz, array+((m+1+j)*elem_sz), elem_sz);
        printf("%d ",  *(int*) (arr2+(j*elem_sz)));

    }

    printf("\n");

    i = 0; j = 0; k = 0;
    while(i < n1 && j < n2){
        if(comp(arr1+i*elem_sz, arr2+j*elem_sz) != 1){
            memcpy(array+k*elem_sz, arr1+i*elem_sz, elem_sz);
            i++;
        }else{
            memcpy(array+k*elem_sz, arr2+j*elem_sz, elem_sz);
            j++; 
        }

        k++;
    }

    while(i < n1){
        memcpy(array+k*elem_sz, arr1+i*elem_sz, elem_sz);
        i++;
        k++;
    }

    while(j < n2){
        memcpy(array+k*elem_sz, arr2+j*elem_sz, elem_sz);
        j++;       
        k++;
    }
    printf("final array: ");
    for(int b = 0; b < k; b++){
        printf("%d ",*(int*) (array+b*elem_sz));
    }
    printf("\n");

    // void* arr1 = malloc(elem_sz*(m-l));
    // void* arr2 = malloc(elem_sz*(r-m));
    // printf("\narr1: ");
    // for(int q = 0; q < lCounter; q++){
    //     memcpy((char*)arr1+q*elem_sz, (char*)array+q*elem_sz, elem_sz);
    //             printf("%d ", *(int*)arr1+q*elem_sz);
    // }    

    // printf("\narr2 stats l:%d, r:%d, m:%d: \n", l, r, m);
    // for(int q = 0; q < rCounter; q++){
    //     // printf("q: %d\n ", *((int*) array+l+q*elem_sz));

    //     memcpy((char*)arr2+q*elem_sz, (char*)array+(l+q)*elem_sz, elem_sz);
    //             printf("%d ", *(int*)arr2+(q+l)*elem_sz);

    // }

    // // printf("i: %d %d %d\n ", *((int*) arr1+i*elem_sz), i, m);
    // // printf("j: %d\n ", *((int*) arr2+j*elem_sz));

    // while(i < lCounter && j < rCounter){
    //     printf("\ncomp: i:%d, j:%d, comp:%d ",*(int*)arr1+elem_sz*i, *(int*)arr2+elem_sz*j, comp(arr1+elem_sz*i, arr2+elem_sz*j));
    //     if(comp(arr1+elem_sz*i, arr2+elem_sz*j) > 0){
    //         memcpy((char*)array+k*elem_sz, (char*)arr1+i*elem_sz, elem_sz);
    //         i += 1;
    //     }else{
    //         memcpy(array+k*elem_sz, arr2+j*elem_sz, elem_sz);
    //         j += 1;
    //     }
    //     k++;
    // }
    
    // while(i < lCounter){
    //     memcpy(array+k*elem_sz, arr1+i*elem_sz, elem_sz);
    //     i += 1;
    // }
    
    // while(j < rCounter){
    //     memcpy(array+k*elem_sz, arr2+j*elem_sz, elem_sz);
    //     j += 1;
    // }
    //     printf("\n");
    // for(int b = 0; b < r-l; b++){
    //     printf("%d ", *(int*)array+b*elem_sz);
    // }

    free(arr1);
    free(arr2);
}

void mergeH(void* array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*), int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergeH(array, len, elem_sz, comp, l, m);
        mergeH(array, len, elem_sz, comp, m+1, r);

        merge(array, len, elem_sz, comp, l, m, r);
    }
}
/* Main sorting algorithm you need to implement */
void mergesort(void*  array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*)){
    mergeH(array, len, elem_sz, comp, 0, len);
}


int main(int argc, char* argv[]){
    int* bal = malloc(sizeof(int)*1024);
    bal[3] = 1;
    bal[2] = 2;
    bal[1] = 3;
    bal[0] = 4;
    bal[4] = 12;
    mergesort(bal, 3, sizeof(int), int_cmp);
    printf("\n%d, %d, %d, %d", *(int*)bal, bal[1], bal[2], bal[3]);
    
    free(bal);
    return 0;
}
