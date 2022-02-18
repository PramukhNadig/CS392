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

int main(int argc, char **argv){
    if(argc == 1){
        printUsage();
        return EXIT_FAILURE;
    }
    FILE *file = fopen
}