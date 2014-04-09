#include <stdio.h>

int main(int argc, char **argv) {

  int ch;

  while(1) {
    ch=getchar();
    if (ch==EOF) break;
    if ((ch==' ') || (ch=='\n')) {
      printf("%c[0m",27);
    }
    else {
      printf("%c[30;47m",27);
    }
    putchar(ch);
  }

  return 0;
}
