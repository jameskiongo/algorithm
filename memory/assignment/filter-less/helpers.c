#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  for (int h = 0; h <= height; h++) {
    for (int w = 0; w <= width; w++) {
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
void sepia(int height, int width, RGBTRIPLE image[height][width]) { return; }

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) { return; }

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  //
  return;
}
