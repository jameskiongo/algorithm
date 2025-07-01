#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *file = fopen("phonebook.csv", "a");
  if (file == NULL) {
    return 1;
  }
  char *name = malloc(12 * sizeof(char));
  char *number = malloc(12 * sizeof(char));
  printf("Name: ");
  scanf("%s", name);
  printf("Number: ");
  scanf("%s", number);

  fprintf(file, "%s, %s\n", name, number);
  free(name);
  free(number);
  fclose(file);
}
