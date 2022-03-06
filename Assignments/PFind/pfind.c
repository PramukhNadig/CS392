#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
 #include <sys/stat.h>


typedef int bool;
#define TRUE  1
#define FALSE 0



bool checkPermissionString(char* pstring);

int main(int argc, char **argv){
    struct stat buf;
    if(stat(argv[1], &buf) < 0){    
        puts("lol retard.\n");
        exit(EXIT_FAILURE);
    }

    printf("lol okay. %d\n", buf.st_mode);

    if(checkPermissionString(argv[2]) == FALSE){
        printf("Error: Permissions string \'%s\'is invalid.", argv[2]);
        exit(EXIT_FAILURE);
    }

    



    return 0;
}




bool checkPermissionString(char* pstring){

    if(strlen(pstring) != 9){
        return FALSE;
    }

    for(int i = 0; i < 9; i++) {
        if(i%3 == 0 && (pstring[i] != 'r' && pstring[i] != '-')){
            return FALSE;
        }
        if(i%3 == 1 && (pstring[i] != 'w' && pstring[i] != '-')){
            return FALSE;
        }
        if(i%3 == 2 && (pstring[i] != 'x' && pstring[i] != '-')){
            return FALSE;
        }   
    }
    return TRUE;
}
