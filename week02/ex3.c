#include <stdio.h>

int main(int argc, char *argv[]) {
 int n;
 if(argc > 1) {
  sscanf(argv[1], "%d", &n);
 } else {
 printf("You have not write an argument");
 return 0;
 }
 for(int i = 0; i < n; i++) {
  for(int j = 1; j <= 2*n-1;j++) {
   if(j >= n - i && j <= n + i) 
    printf("*");
   else
    printf (" ");
  }
  printf("\n");
 }
}
