#include "std392io.h"

int output(char* filename, char format, void* data){

  int fd;
  if(strcmp(filename,"") == 0){
    fd = STDOUT_FILENO;
  }else{
    fd = open(filename, O_WRONLY|O_APPEND|O_CREAT, 0666);

  }


    if(format != 's' && format != 'd'){
        errno = EIO;
        return -1;
    } 

    if(data == NULL){
        errno = EIO;

        return -1;
    }

    lseek(fd, 0, SEEK_END);

    if(format == 's'){
        char* s = data;

        write(fd, s, strlen(s));
        __writeLine(fd);

    }else{
        int k = *(int *) data;
        char* s = __toString(k);
        write(fd, s, strlen(s));
        __writeLine(fd);

        free(s);
    }


    return 0;
}

int input(char* filename, char format, void* data){
  int fd;
  int sizeMul = 1;
  int count = 0;
  char* str = malloc(sizeof(char)*128 * sizeMul);
  char c[1];
  if((fd = open(filename, O_RDONLY)) < 0){
    errno = ENOENT;
    return -1;
  }

    while(read(fd, &c, 1)){
      if(*c =='\n'){
        break;
      }
      if(count++ == sizeMul*128){
      str = realloc(str, sizeof(char)*128 * ++sizeMul);
      }

      strncat(str, c, 1);
    }
    printf("%s\n", str);
    *data = &str;

    return 0;
}

int clean(){
    return 0;
}



char* __toString(int k){
 char* str = (char*) malloc (sizeof(char) * __lenOfNum(k) + 1);
  int i = 0;

 if(k < 0){
    str[0] = '-';
    i++;
    k = k*-1;
  }
  k = __reverse(k);
  while(k >= 1){
    str[i] = __intToAscii(k%10);
    k /= 10;
    i++;
  }

  str[i] = '\0';

  return str;
  
}

int __intToAscii(int number) {
   return '0' + number;
}

int __lenOfNum(int k){
  int i = 0;

  if(k < 0){
    k *= -1;
    i++;
  }
  while(k > 1){
    k/=10;
    i++;
  }

  return i;
}

int __reverse(int n){
    int reverse = 0, remainder;
    while (n != 0) {
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
  }
  return reverse;
}

int __writeLine(int fd){
  return write(fd, "\n", 1);
}