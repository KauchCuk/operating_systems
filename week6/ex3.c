#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void interrupt(int i) {
 printf("\nInterrupt occurs, closing...\n");
 exit(1);
}

int main() {
 while(1) {
  signal(SIGINT, interrupt);
 }
 return 0;
}
