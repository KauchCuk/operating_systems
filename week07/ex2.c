#include <stdio.h>
#include <stdlib.h>

int main() {
 int size;
 scanf("%d", &size);
 int *array = malloc(size*sizeof(int));
 for(int i = 0; i < size; i++) {
  array[i] = i;
  printf("%d ", array[i]);
 }
 printf("\n");
 free(array);
 return 0;
}
