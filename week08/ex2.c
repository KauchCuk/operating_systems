#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
 for(int i = 0; i < 10; i++) {
  int* arr = malloc(1024*2500*sizeof(int));
  memset(arr, 0, 1024*2500*sizeof(int));
  sleep(1);
 }
 return 0;
}
