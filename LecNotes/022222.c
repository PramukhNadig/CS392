/*
 * Write a program to check the group's permission to execute. The filename is passed as a 
 * command lines argument 
*/
#include <sys/stat.h>
#include <stdio.h>



int main(int argc, char ** argv){

    struct stat st;

    char* filename = argv[1];


    int r = stat(argv[1], &st);
    if(r == -1){
        printf("Error: Cannot open %s", filename);
        exit(EXIT_FAILURE);
    }

    if( fs.st_mode & S_IXGRP){
        puts("group execute permission allowed !");
    }
    else{
        puts("group execute permission denied !");
    }
    return EXIT_SUCCESS;
}