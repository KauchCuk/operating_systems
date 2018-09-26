#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main() {
 int child = fork();
 if(child == 0) {
  while(1) {
   printf("(child) I'm alive\n");
   sleep(1);
  }
 } else {
  sleep(10);
  kill(child, SIGTERM);
  printf("Child killed\n");
 }
 return 0;
}
