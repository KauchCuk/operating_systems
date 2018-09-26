#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 40

int main() {
 int pipe_it[2];
 pipe(pipe_it);
 int first_child = fork();
 if(first_child == 0) {
  int second_child = 0;
  char second_child_id[BUF_SIZE];
  while(!second_child) {
   read(pipe_it[0], second_child_id, BUF_SIZE);
   second_child = atoi(second_child_id);
  }
  printf("(1st child) Got 2nd id, hehe\n");
  sleep(5);
  printf("(1st child) I guess the 2nd wants to sleep a lil bit\n");
  kill(second_child, SIGSTOP);
  printf("(author) And they will wait for 2nd's get up forever, because SIGSTOP does not change the state\n");
  sleep(5);
  printf("(1st child) Hmmm, parent is not triggered, I don't wanna do it, but\n");
  printf("*sounds of shooting*\n");
  kill(second_child, SIGKILL);
 } else {
  int second_child = fork();
  if(second_child == 0) {
   while(1) {
    printf("(2nd child) Living\n");
    sleep(1);
   }
  } else {
   char second_child_id[BUF_SIZE];
   int zero = 0;
   sprintf(second_child_id, "%d", second_child);
   write(pipe_it[1], second_child_id, strlen(second_child_id));
   printf("(parent) Sending 2nd's id to 1st\n");
   printf("(parent) Let's follow the 2nd now\n");
   waitpid(second_child, &zero, 0);
   printf("(parent) Hey, 1st, where is 2nd?\n");
  }
 }
 return 0;
}
