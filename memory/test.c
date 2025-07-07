#include <math.h>
#include <stdio.h>
typedef struct {
  int rgbtBlue, rgbtGreen, rgbtRed; // Red, Green, Blue components
} Pixel;
int main(void) {
  int height = 3;
  int width = 3;
  Pixel image[3][3] = {// First row
                       {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}},
                       // Second row
                       {{110, 130, 140}, {120, 140, 150}, {130, 150, 160}},
                       // Third row
                       {{200, 210, 220}, {220, 230, 240}, {240, 250, 255}}};
  Pixel copy[height][width];
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      int height_limit = height - 1;
      int width_limit = width - 1;
      float red_sum = 0;
      float blue_sum = 0;
      float green_sum = 0;
      float numbers = 0;
      copy[h][w] = image[h][w];

      for (int i = (h - 1 < 0 ? 0 : h - 1);
           i <= (h + 1 > height_limit ? height_limit : h + 1); i++) {
        for (int k = (w - 1 < 0 ? 0 : w - 1);
             k <= (w + 1 > width_limit ? width_limit : w + 1); k++) {
          printf("%.2f + %i ", red_sum, image[i][k].rgbtRed);
          /* printf("%i ", image[i][k].rgbtRed); */

          red_sum += image[i][k].rgbtRed;
          blue_sum += image[i][k].rgbtBlue;
          green_sum += image[i][k].rgbtGreen;
          numbers++;
        }
      }
      printf("\n");
      /* printf("=%f\n", red_sum); */
      int red_average = round(red_sum / numbers);
      /* printf("average= %i\n", red_average); */
      int blue_average = round(blue_sum / numbers);
      int green_average = round(green_sum / numbers);
      copy[h][w].rgbtRed = red_average;
      copy[h][w].rgbtBlue = blue_average;
      copy[h][w].rgbtGreen = green_average;
    }
  }
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      image[h][w].rgbtGreen = copy[h][w].rgbtGreen;
      image[h][w].rgbtBlue = copy[h][w].rgbtBlue;
      image[h][w].rgbtRed = copy[h][w].rgbtRed;
    }
  }
}
