#include "mergesort.h"


/* Functions to compare a and b */
int int_cmp(const void* a, const void* b){
    if((int) a == (int) b) return 0;

    return (int) a > (int) b ? 1 : 0
}
int dbl_cmp(const void* a, const void* b){
    if((double) a == (double) b) return 0;

    return (double) a > (double) b ? 1 : -1
}

/* Main sorting algorithm you need to implement */
void mergesort(void*  array,
               size_t len,
               size_t elem_sz,
               int (*comp)(const void*, const void*));

int main(int argc, char** argv){
    int i = 0;
    int j = 16;
    cout << "Mergesort " << int_cmp(&i, &j) << endl;
}
