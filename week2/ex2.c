#include <stdio.h>
#include <string.h>

int main() {
 char s[64];
 int len;
 printf("Enter the string: \n");
 fgets(s, 64, stdin);
 len = strlen(s);
 for(int i = len - 1; i >= 0; i--) {
  printf("%c", s[i]);
 }
 printf("\n");
 return 0;
}
