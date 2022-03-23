#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>

int output(char*, char, void*);

int input(char*, char, void*);

int clean();

//char* __convert(int);

char *__toString(int);

int __intToAscii(int);

int __reverse(int);

int __lenOfNum(int);

int __writeLine(int);