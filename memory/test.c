#include <math.h>
#include <stdio.h>

int main(void) {
  int arr[5][5] = {{1, 2, 3, 4, 5},
                   {6, 7, 8, 9, 10},
                   {11, 12, 13, 14, 15},
                   {16, 17, 18, 19, 20},
                   {21, 22, 23, 24, 25}};
  int width_limit = 5 - 1;
  int height_limit = 5 - 1;
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
      printf("Neighbors around element %d at (%d, %d):\n", arr[x][y], x, y);
      float numbers = 0.0;
      float sum = 0.0;
      for (int i = (x - 1 < 0 ? 0 : x - 1);
           i <= (x + 1 > height_limit ? height_limit : x + 1); i++) {
        for (int k = (y - 1 < 0 ? 0 : y - 1);
             k <= (y + 1 > width_limit ? width_limit : y + 1); k++) {
          printf("%i ", arr[i][k]);
          sum += arr[i][k];
          numbers++;
        }
        printf("\n");
      }
      printf("numbers: %f ", numbers);
      printf("Sum: %f ", sum);
      int average = round(sum / numbers);
      printf("average: %i ", average);
      printf("\n");
    }
  }
}
