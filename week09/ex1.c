#include <stdio.h>
#include <stdlib.h>

int* pages;
int* r;
unsigned char* ages;
int capacity;

int put_page(int new_page) {
 for(int i = 0; i < capacity; i++) {
  if(pages[i] == -1) {
   pages[i] = new_page;
   return 0;
  }
 }
 int oldest = 0;
 for(int i = 0; i < capacity; i++) {
  if(ages[i] < ages[oldest]) {
   oldest = i;
  }
 }
 pages[oldest] = new_page;
 ages[oldest] = 0;
 r[oldest] = 1;
 return 1;
}

void calc_age() {
 for(int i = 0; i < capacity; i++) {
  ages[i] = ages[i] >> 1;
  ages[i] = ages[i] | r[i]*128;
  r[i] = 0;
 }
}

int reference_page(int page) {
 int page_fault = 1;
 for(int i = 0; i < capacity && page_fault; i++) {
  if(pages[i] == page) {
   page_fault = 0;
   r[i] = 1;
  } else {
  }
 }
 if(page_fault) {
  put_page(page);
 }
 calc_age();
 return !page_fault;
}

int main() {
 int misses = 0;
 int hits = 0;
 FILE *file;
 char digit;
 int page_number;

 scanf("%d", &capacity);
 pages = malloc(capacity*sizeof(int));
 r = malloc(capacity*sizeof(int));
 ages = malloc(capacity*sizeof(int));
 for(int i = 0; i < capacity; i++) {
  pages[i] = -1;
  ages[i] = 0;
  r[i] = 0;
 }

 file = fopen("09input.txt", "r");
 while(digit != EOF) {
  page_number = 0;
  do {
   digit = fgetc(file);
   if(digit != ' ' && digit != EOF) {
    page_number = page_number * 10 + atoi(&digit);
   } else {
    break;
   }
  } while (1);
  if(reference_page(page_number)) {
   hits++;
  } else {
   misses++;
  }
 }
 printf("Hit/Miss ratio: %d/%d\n", hits, misses);
}
