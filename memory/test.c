#include <stdio.h>

int main(void) {
  int buffer[10];
  FILE *file = fopen("phonebook.csv", "r");
  if (file == NULL) {
    return 1;
  }
  int result = fread(buffer, sizeof(int), 1, file);
  printf("%i\n", result);
}
