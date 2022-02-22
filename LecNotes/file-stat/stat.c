#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat fileinfo;
    char filename[] = "filestat.c";
    int status = stat(filename, &fileinfo);
    printf("%d\n", status);

    printf("Inode number: %llu\n", fileinfo.st_ino);
    printf("User ID: %d\n", fileinfo.st_uid);
    printf("Total size: %d\n", fileinfo.st_size);
    printf("# Blocks: %d\n", fileinfo.st_blocks);

    if (S_ISREG(fileinfo.st_mode)) {
        printf("It's a regular file! %x\n", fileinfo.st_mode);
    }
    else {
        printf("It's not a regular file!\n");
    }


    return 0;
}
