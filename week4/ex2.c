// After execution in background program in first iteration creates 8 processes with itself
// and in second it. 64 procesess.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define STOP 2

int main() {
 for(int i = 0; i < STOP; i++) {
 fork();
 fork();
 fork();
 sleep(5);
 }
}
