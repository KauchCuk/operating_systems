#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
 setvbuf(stdout, NULL, _IOLBF, 1024);
 printf("H");
 sleep(1);
 printf("e");
 sleep(1);
 printf("l");
 sleep(1);
 printf("l");
 sleep(1);
 printf("o");
 sleep(1);
 printf("\n");
}
