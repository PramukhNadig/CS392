#include "std392io.h"

int main(int argc, char **argv){
    int k = -12;
    char* s;
    // toString(23);
    // char* l = toString(18272);
    // printf("%s\n", l);
    write(1, "wowzers", 5);
    output("wow.txt", 'd', &k);
    output("wow.txt", 'd', &k);
    input("wow.txt", 's', &s);

}