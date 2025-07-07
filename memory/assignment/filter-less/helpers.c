#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      float sum = 0.0;
      sum = sum + image[h][w].rgbtBlue;
      sum = sum + image[h][w].rgbtGreen;
      sum = sum + image[h][w].rgbtRed;
      int average = round(sum / 3);
      image[h][w].rgbtBlue = average;
      image[h][w].rgbtGreen = average;
      image[h][w].rgbtRed = average;
    }
  }
  /* return; */
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      int original_blue = image[h][w].rgbtBlue;
      int original_green = image[h][w].rgbtGreen;
      int original_red = image[h][w].rgbtRed;
      // sepia
      int sepia_blue = round((.272 * original_red) + (.534 * original_green) +
                             (.131 * original_blue));
      if (sepia_blue > 255) {
        sepia_blue = 255;
      }
      int sepia_green = round((.349 * original_red) + (.686 * original_green) +
                              (.168 * original_blue));
      if (sepia_green > 255) {
        sepia_green = 255;
      }
      int sepia_red = round((.393 * original_red) + (.769 * original_green) +
                            (.189 * original_blue));
      if (sepia_red > 255) {
        sepia_red = 255;
      }
      image[h][w].rgbtBlue = sepia_blue;
      image[h][w].rgbtGreen = sepia_green;
      image[h][w].rgbtRed = sepia_red;
    }
  }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
  for (int h = 0; h < height; h++) {
    for (int w = 0, q = (width - 1); w < width / 2 && q >= width / 2;
         w++, q--) {
      int blue_temp = image[h][w].rgbtBlue;
      int green_temp = image[h][w].rgbtGreen;
      int red_temp = image[h][w].rgbtRed;
      image[h][w].rgbtBlue = image[h][q].rgbtBlue;
      image[h][w].rgbtGreen = image[h][q].rgbtGreen;
      image[h][w].rgbtRed = image[h][q].rgbtRed;
      /**/
      image[h][q].rgbtBlue = blue_temp;
      image[h][q].rgbtGreen = green_temp;
      image[h][q].rgbtRed = red_temp;
    }
  }

  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  RGBTRIPLE copy[height][width];
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
          red_sum += image[i][k].rgbtRed;
          blue_sum += image[i][k].rgbtBlue;
          green_sum += image[i][k].rgbtGreen;

          numbers++;
        }
      }
      int red_average = round(red_sum / numbers);
      int blue_average = round(blue_sum / numbers);
      int green_average = round(green_sum / numbers);
      copy[h][w].rgbtBlue = blue_average;
      copy[h][w].rgbtGreen = green_average;
      copy[h][w].rgbtRed = red_average;
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
