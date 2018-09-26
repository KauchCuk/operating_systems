#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 200

void main() {
 char input[BUF_SIZE];
 char stop[] = "stop\n";
 do {
  fgets(input, BUF_SIZE, stdin);
  system(input);
 } while (strcmp(input, stop) != 0);
}
