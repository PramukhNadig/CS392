#include <stdio.h>


void addone(void* arr, size_t len, size_t elem_sz){
        
}


int main() {

    int test1[] = {1,2,3,4,5};
    addone(/* pass parameters */);
    for (size_t i = 0; i < 5; i ++) printf("%d\n", test1[i]);

    double test2[] = {0.3, -0.2, 1.34};
    addone(/* pass parameters */);
    for (size_t i = 0; i < 3; i ++) printf("%lf\n", test2[i]);

    char test3[] = {'3', 'a', 'Z', '?'};
    addone(/* pass parameters */);
    for (size_t i = 0; i < 4; i ++) printf("%c\n", test3[i]);

    return 0;
}
