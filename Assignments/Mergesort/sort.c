/**
 * @file sort.c
 * @author Pramukh Nadig (pnadig@stevens.edu)
 * I pledge my honor that I've abided by the Stevens Honor System
 * @version 1.0
 * @date 2022-02-18
 * 
 */

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>
#include "mergesort.h"

#define MAX_ELEM 1024

void printUsage(){
    printf("Usage: ./sort [-i|-d] filename\n");
    printf("-i: Specifies the file contains ints.\n");
    printf("-d: Specifies the file contains doubles.\n");
    printf("filename: The file to sort.\n");

}

int main(int argc, char **argv){
    int i = 0, d = 0;
    if(argc == 1){
        printUsage();
        return EXIT_FAILURE;
    }
    FILE *file;
    int opt;
    while ((opt = getopt(argc, argv, ":if:id")) != -1) {
        switch(opt){
            case 'i':
                i++;
                if(argc == 2){
                    printf("Error: No input file specified.\n");
                    return EXIT_FAILURE;
                }else if(argc > 3){
                    printf("Error: Too many files specified.\n");
                    return EXIT_FAILURE;
                }else{
                    file = fopen(argv[2], "r");
                    if(file == NULL){
                        printf("Error: Cannot open '%s'. No such file or directory.\n", argv[2]);
                        return false;
                    }
                }
                break;
            case 'd':
                d++;
                if(argc == 2){
                    printf("Error: No input file specified.\n");
                    return EXIT_FAILURE;
                }else if(argc > 3){
                    printf("Error: Too many files specified.\n");
                    return EXIT_FAILURE;
                }else{
                    file = fopen(argv[2], "r");
                    if(file == NULL){
                        printf("Error: Cannot open '%s'. No such file or directory.\n", argv[2]);
                        return EXIT_FAILURE;
                    }
                }            
                break;
            case '?':
                fprintf(stderr, "Error: Unknown option '%s' received.\n", argv[1]);
                printUsage();
                return EXIT_FAILURE;
                break;
       }

       if(d+i > 1){
           printf("Error: Too many flags specified.\n");
           return EXIT_FAILURE;
       }
    }
    if(argc < 3){
        printUsage();
        return EXIT_FAILURE;
    }


    if(i == 1){
        int *temp = malloc(MAX_ELEM * sizeof(int));
        int n, len = 0;
        while(fscanf(file, "%d\n", &n) != EOF){
            temp[len++] = n;
        }



        mergesort(temp, len-1, sizeof(int), int_cmp);

        for(int j = 0; j < len; j++){
            printf("%d ", *(temp+j));
        }    

        free(temp);
    }else if(d == 1){
        double *temp = malloc(MAX_ELEM * sizeof(double));
        double n;
        int len = 0;
        while(fscanf(file, "%lf\n", &n) != EOF){
            temp[len++] = n;
        }

        mergesort(temp, len-1, sizeof(double), dbl_cmp);
        for(int j = 0; j < len; j++){
            printf("%lf ", *(temp+j));
        }    
        free(temp);
    }
    printf("\n");
    fclose(file);
    return EXIT_SUCCESS;
}