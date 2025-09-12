#include "3DVector.h"
#include "Window.h"
#include <iostream>

int main(){

    Vector3 a = {1,1,1};
    Vector3 b = {1,2,3};
    double scalar = 2.0;

    Vector3 result = vector3Addition(a, b);

    printVector3(result);

    result = vector3Subtraction(a, b);

    printVector3(result);

    result = vector3ScalarMult(b,scalar);

    printVector3(result);

    // return display();
}