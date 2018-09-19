#include <stdio.h>
#include <pthread.h>

#define N 10

pthread_t threadsId[N];

void* greetings(int i) {
 printf("Thread %lu created in iteraton %d greetings you!\n", pthread_self(), i);
 pthread_exit(0);
}

int main() {
 for(int i = 0; i < N; i++) {
  pthread_create(&threadsId[i], NULL, greetings, i);
  printf("(%lu) Thread %lu created on iteration %d.\n", pthread_self(), threadsId[i], i);
  // Line below fixes the program in the way that each thread creates, prints and exits separatly
  pthread_join(threadsId[i], NULL);
 }
 return 0;
}
