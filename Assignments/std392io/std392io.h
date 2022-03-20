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

char *toString(int);
