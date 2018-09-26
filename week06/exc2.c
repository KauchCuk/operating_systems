#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define STR_SIZE 200

int main() {
 char first_string[] = "Hello Operating System\n";
 int pipe_it[2];
 int child;
 child = fork();
 if(child != 0) {
  write(pipe_it[1], first_string, strlen(first_string));
  close(pipe_it[1]);
  exit(0);
 } else {
  char second_string[STR_SIZE];
  read(pipe_it[0], second_string, STR_SIZE);
  printf("%s", second_string);
  close(pipe_it[0]);
  exit(0);
 }
  return 0;
}
