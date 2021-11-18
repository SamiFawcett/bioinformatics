#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n)
{
 if (n == 0)
 {
  return 0;
 }
 if (n == 1)
 {
  return 1;
 }
 return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char **argv)
{
 /* Given a positive integer n less than or equal to 25 return the value of F_n where F_n describes the nth fibonancci number*/
 int fn = fibonacci(25);
 printf("%d", fn);
 return 1;
}