#include <GLFW/glfw3.h>
#include <iostream>
#include "Color.h"
#include "3DVector.h"
#include "Triangle.h"
#include "2DVector.h"

#define START_HEIGHT 900
#define START_WIDTH 1600

#define ASPECT_RATIO_HEIGHT 9
#define ASPECT_RATIO_WIDTH 16

#define BACKGROUND_COLOR Color(0, 0, 0)

#define X_MAX 8
#define X_MIN -8
#define Y_MAX 4.5
#define Y_MIN -4.5


void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, std::vector<unsigned char>& framebuffer, int width);
void drawGradient(std::vector<unsigned char>& framebuffer, int width, int height);


struct Scene {
    std::vector<Triangle3D> triangles;
    Vector3 camera, cameraAngle, focalLength; //focalLength usually (0, 0, f) where f is the focal length of the camera to the screen

    void drawScene(std::vector<unsigned char>& framebuffer, int width, int height);
    int display();
};