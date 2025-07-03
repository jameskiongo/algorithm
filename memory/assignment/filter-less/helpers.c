#include "helpers.h"
#include <math.h>

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
void reflect(int height, int width, RGBTRIPLE image[height][width]) { return; }

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  //
  return;
}
