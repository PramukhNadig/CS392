
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

//I pledge my honor that I've abided by the stevens honor code.



int checkFiles(FILE* file1, FILE* file2){
    int curr1, curr2;
    while(fscanf(file1, "%d", &curr1) != EOF && fscanf(file2, "%d", &curr2) != EOF){
        if(curr1 != curr2){
            printf("%d %d\n", curr1, curr2);
            return 0;
        }
    }

    return 1;
}

void swap(char *x,char *y)
{
	char t;
	t=*x;
	*x=*y;
	*y=t;
}

void little2big(int* arr, int len){
    for(int i=0; i<len; i++){
        unsigned char* ptr = (unsigned char*) &arr;
        
        ptr[3] = ptr[0];
        }

    

    // for(int i = 0; i < len; i++){
    //      int n = htonl(arr[i]);
    //      memcpy(&arr[i], &n, sizeof(int));
    //  }

    //bit mas to convert from little endian to big endian
    // for(int i = 0; i < len; i++){
    // int num = arr[i];
    // int swapped = ((num>>24)&0xff) |
    //         ((num<<8)&0xff0000) |
    //         ((num>>8)&0xff00) |
    //         ((num<<24)&0xff000000); 
                    
    // memcpy(&arr[i], &swapped, sizeof(int));

    // }
}


int main(int argc, char **argv){
    FILE* file = fopen(argv[1], "r");
    char* line;
    int size = 0;
    int curr;
    
    while(fscanf(file, "%d", &curr) != EOF){
        size++;
    }

    rewind(file);
    int *array = (int*) malloc(size * sizeof(int));
    size = 0;
    while(fscanf(file, "%d", &curr) != EOF){
        array[size++] = curr;
    }



    FILE* fp = fopen(argv[2], "w+");
    little2big(array, size);
    for(int i = 0; i < size; i++){
        fprintf(fp, "%d\n", (array[i]));
    }   


    rewind(fp);
    
    FILE* fp2 = fopen("check.txt", "r");
    printf("%d\n", (checkFiles(fp2,fp)));
    free(array);
    fclose(fp);
    fclose(file);
    return 0;
}

