#include <stdio.h>
#include <string.h>

int main() {
 char** s;
 char foo[] = "Hello world";
 s = &foo;
 printf("s is %s\n", s);
 s[0] = foo;
 printf("s[0] is %s\n", s[0]);
 return 0;
}
