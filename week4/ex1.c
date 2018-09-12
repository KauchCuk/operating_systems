// Child process alwasys has PARENT_ID + 1 process id

#include <stdio.h>
#include <sys/types.h>
#include <string.h>

#define N         10
#define BUF_SIZE  200

void main() {
 int ppid = getpid();
 int n = N;
 char buf[BUF_SIZE];
 int cpid = fork();
 if(getpid() == ppid) {
  sprintf(buf, "Hello from parent [%d]\n", ppid - N);
 } else {
  sprintf(buf, "Hello from child [%d]\n", getpid() - N);
 }
 write(1, buf, strlen(buf));
}


