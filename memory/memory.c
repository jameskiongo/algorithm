#include <stdio.h>

int main(void) {
  char *c = "Hello, World!";
  int n = 50;
  int *p = &n;
  printf("%i\n", *p);
  printf("%s\n", c);
  return 0;
}
