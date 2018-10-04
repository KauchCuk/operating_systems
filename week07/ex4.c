#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <string.h>

#define ARR_SIZE 10

void* reallocate(void* ptr, size_t bytes) {
 size_t prev = malloc_usable_size(ptr);
 void* new_ptr = malloc(bytes);
 if(bytes < prev) {
  memcpy(new_ptr, ptr, bytes);
 } else {
  memcpy(new_ptr, ptr, prev);
 }
 free(ptr);
 return new_ptr;
}

int main() {
 int size1;
 scanf("%d", &size1);
 int* a = malloc(size1*sizeof(int));
 for(int i = 0; i < size1; i++) {
  a[i] = i*2;
  printf("%d ", a[i]);
 }
 printf("\n%u\n", (unsigned int)a);
 scanf("%d", &size1);
 a = reallocate((void*)a, size1*sizeof(int));
 for(int i = 0; i < size1; i++) {
  printf("%d ", a[i]);
 }
 printf("\n%u\n", (unsigned int)a);
 return 0;
}
