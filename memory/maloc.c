#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *s = "hi!";
  int n = strlen(s);
  char *t = malloc(n + 1);
  if (t == NULL) {
    return 1;
  }
  for (int i = 0; i <= n; i++) {
    t[i] = s[i];
  }
  stpcpy(t, s);
  printf("s: %s\n", s);
  printf("t: %s\n", t);
  /* free(t); */
}
