#include <stdio.h>

#define ARR_SIZE(a) (sizeof(a)/sizeof(*a))

void swap(int *a, int *b) {
 int tmp = *a;
 *a = *b;
 *b = tmp;
}


void bubbleSort(int *array, int size) {
 for(int i = 0; i < size - 1; i++) {
  for(int j = 0; j < size - i - 1; j++) {
   if(array[j] > array[j + 1]) {
    swap(&array[j], &array[j + 1]);
   }
  }
 }
}

void printArray(int *array, int size) {
 for(int i = 0; i < size; i++) {
  printf("%d ", array[i]);
 }
}

int main() {
 int i_array[] = {1, 4, 7, 8, 9, 2, 3, 5};
 bubbleSort(i_array, ARR_SIZE(i_array));
 printArray(i_array, ARR_SIZE(i_array));
 return 0;
}

