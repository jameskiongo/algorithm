#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *string = malloc(8 * sizeof(char));
  // potential but: not specified the amount of memory to allocate to string
  printf("string: ");
  scanf("%s", string);
  // scan f expects the address to a variable;
}
