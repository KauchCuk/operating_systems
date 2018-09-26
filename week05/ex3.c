#include <stdio.h>
#include <pthread.h>

#define BUF_SIZE 20

int buffer[BUF_SIZE];
int count;
int i;
int sleep_prod = 0;
int sleep_cons = 0;

void *producer(void *data) {
 while(1) {
  if(sleep_prod == 0) {
   if(count == BUF_SIZE) {
    printf("PRODUCER going to sleep\n");
    sleep_prod = 1;
   } else {
    int tmp = i;
    buffer[count] = tmp;
    printf("(%d, count: %d)%d was recorded\n", tmp, count, buffer[count]);
    count++;
    i++;
    sleep_cons = 0;
   }
  }
 }
}

void *consumer(void *data) {
 while(1) {
  if(sleep_cons == 0) {
   if(count == 0) {
    printf("CONSUMER going to sleep\n");
    sleep_cons = 1;
   } else {
    if(buffer[count] == BUF_SIZE) count--;
    int tmp = buffer[count];
    buffer[count] = -1;
    printf("(%d, count: %d)%d was removed\n", i, count, tmp);
    count--;
    i++;
    sleep_prod = 0;
   }
  }
 }
}

void main() {
 pthread_t prod, cons;
 pthread_create(&prod, NULL, producer, (void*)NULL);
 pthread_create(&prod, NULL, consumer, (void*)NULL);
 while(1) {}
}
