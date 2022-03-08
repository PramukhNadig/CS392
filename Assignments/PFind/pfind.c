/**
 * @file pfind.c
 * @author Pramukh Nadig (pnadig@stevens.edu)
 * @brief  Finds files with the same permissions as the given string in a directory
 * @version 1.0
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 *  I pledge my honor that I've abided by the Stevens Honor Code
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>

typedef int bool;
#define TRUE  1
#define FALSE 0



//Put prototypes here since I wanted my main function at the top
//Validate the Permission String
bool checkPermissionString(char* pstring);
//Check file permissions
int checkFilePermission(char* file);
//Convert the pstring given to an integer to allow comparisons with files
int getPermissionNumber(char* pstring);
//Test function to print out permissions (later discovered ls -la)
char* permissions(char *file);
//Convert Decimal number to an octal number since it was required to convert the file perms to the perms I used in getPermissionNumber
int convertDecimalToOctal(int decimalNumber);
//The recursive function that goes through all directories and prints everything out
void dirEnter(char* dirn, int pnum);

int main(int argc, char **argv){


    if(checkPermissionString(argv[2]) == FALSE){
        printf("Error: Permissions string \'%s\'is invalid.\n", argv[2]);
        exit(EXIT_FAILURE);
    }       

    dirEnter(argv[1], (getPermissionNumber(argv[2])));


    return 0;
}


int checkFilePermission(char* file){
    struct stat ret;

    if (stat(file, &ret) == -1) {
        return -1;
    }

             int mode = ret.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
             return mode;

}

int convertDecimalToOctal(int decimalNumber)
{
    int octalNumber = 0, i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
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

int getPermissionNumber(char* pstring){
    int sum = 0;
    int subNum = 1000;
    for(int i = 0; i < strlen(pstring); i++) {
        
        if(i%3 == 0){
            subNum /= 10;
            
        }
        if(pstring[i] == 'x'){
            sum += 1 * subNum;
        }     
        if(pstring[i] == 'w'){
            sum += 2 * subNum;
        }       
         if(pstring[i] == 'r'){
            sum += 4 * subNum;
        }


    }
    return sum;

}


char* permissions(char *file){
    struct stat st;
    char *modeval = malloc(sizeof(char) * 9 + 1);
    if(stat(file, &st) == 0){
        int perm = st.st_mode;
        modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
        modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
        modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
        modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
        modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
        modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
        modeval[6] = (perm & S_IROTH) ? 'r' : '-';
        modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
        modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
        modeval[9] = '\0';

        puts("\n");
        return modeval;     
    }
}
void dirEnter(char* dirname, int pnum){
    if(chdir(dirname) == -1){
        fprintf(stderr, "Error: Cannot open directory '%s'. %s\n", dirname, strerror(errno));
        exit(EXIT_FAILURE);
    }

    char path[1024];
    getcwd(path, 1024); 

    struct dirent *dirp;
    DIR* dp;
    struct stat fileinfo;
    dp = opendir(path);

    if(dp ==  NULL){
        fprintf(stderr, "Error: Cannot open directory '%s'. %s\n", dirname, strerror(errno));
        exit(EXIT_FAILURE);
    }

    while((dirp = readdir(dp)) != NULL){ 
        stat(dirp->d_name, &fileinfo);
        
        if(strcmp(dirp->d_name,".") == 0|| strcmp(dirp->d_name,"..") == 0){


        }
        else if(S_ISDIR(fileinfo.st_mode)){
            char filepath[1024]; 
            getcwd(filepath, 1024); 
            strcat(filepath,"/");
            strcat(filepath,dirp->d_name); 
            dirEnter(filepath, pnum); 
        }
        else{ 
            int mode = convertDecimalToOctal(checkFilePermission(dirp->d_name));
            if(mode == pnum){ 
                char filepath[1024]; 
                getcwd(filepath, 1024); 
                strcat(filepath,"/");
                strcat(filepath,dirp->d_name);
                printf("%s\n", filepath);
            }
        }
    }

    closedir(dp);
    chdir("..");


}
