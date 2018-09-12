#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
 int i = INT_MAX;
 float f = FLT_MAX;
 double d = DBL_MAX;
 printf("The size of int is: %lu, the max value is: %d\n", sizeof(int), i);
 printf("The size of float is %lu, the max value is: %f\n", sizeof(float), f);
 printf("The size of double is %lu, the max value is %f\n", sizeof(double), d);
 return 0;
}
