/**
* When sending kill and stop signals, program does not handle it and immediately stops/pauses
* but it handles the usr1 signal
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void kill_handler(int i) {
 printf("Killing signal occurs, closing...\n");
 exit(1);
}

void stop_handler(int i) {
 printf("Stop signal occurs, pausing...\n");
 exit(1);
}

void usr_handler(int i) {
 printf("User signal occurs, ignoring...\n");
 fflush(stdout);
}

int main() {
 while(1) {
  signal(SIGKILL, kill_handler);
  signal(SIGSTOP, stop_handler);
  signal(SIGUSR1, usr_handler);
 }
}
