#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <string.h>

int main() {
 for(int i = 0; i < 10; i++) {
  int* chunk = malloc(10*1024*1024*sizeof(char));
  memset(chunk, 0, 10*1024*1024*sizeof(char));
  struct rusage* resources = malloc(sizeof(struct rusage));
  getrusage(RUSAGE_SELF, resources);
  printf("At iteration %d I am using: %ld\n", i, resources->ru_maxrss);
  sleep(1);
 }
}
