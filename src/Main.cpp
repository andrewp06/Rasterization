#include "Window.h"
#include <iostream>

int main(){

    Scene scene;
    scene.triangles = {{{0,0,10}, {0,2,10}, {-5, 5, 10}, {255, 0, 0}}, {{0,0,10}, {0,2,10}, {5, 4, 5}, {0, 255, 0}}};
    scene.camera = {0,0,0};
    scene.cameraAngle = {0,0,0};
    scene.focalLength = {0,0,5};
    scene.display();
}