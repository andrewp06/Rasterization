#include <GLFW/glfw3.h>
#include <iostream>
#include "Color.h"

#define START_HEIGHT 900
#define START_WIDTH 1600

#define ASPECT_RATIO_HEIGHT 9
#define ASPECT_RATIO_WIDTH 16

#define BACKGROUND_COLOR = 

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, std::vector<unsigned char>& framebuffer, int width);
void drawGradient(std::vector<unsigned char>& framebuffer, int width, int height);
int display();