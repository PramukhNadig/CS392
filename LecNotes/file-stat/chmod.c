#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char** argv) {

    struct stat buffer;
    if ((stat(argv[1], &buffer)) == -1) {
        fprintf(stderr, "No such file!\n");
        exit(EXIT_FAILURE);
    }

    int mode = buffer.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    printf("%o\n", mode);

    printf("%o\n", S_IRWXU | S_IRWXG | S_IRWXO);
    chmod(argv[1], S_IRWXU | S_IRWXG | S_IRWXO);

    stat(argv[1], &buffer); /* "Refresh stat": IMPORTANT! */
    mode = buffer.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    printf("%o\n", mode);

    exit(EXIT_SUCCESS);
}