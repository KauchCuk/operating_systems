#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define STR_SIZE 200

int main() {
 char first_string[] = "Hello Operating System\n";
 char second_string[STR_SIZE];
 int pipe_it[2];
 write(pipe_it[1], first_string, strlen(first_string));
 read(pipe_it[0], second_string, STR_SIZE);
 printf("%s", second_string);
 close(pipe_it[0]);
 close(pipe_it[1]);
 return 0;
}
