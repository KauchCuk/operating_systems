#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define STOP 10

int main() {
 for(int i = 0; i < STOP; i++) {
 fork();
 fork();
 fork();
 sleep(5);
 }
}
