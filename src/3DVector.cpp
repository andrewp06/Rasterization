#include "3DVector.h"
#include <iostream>

struct Vector3;

Vector3 vector3Addition(Vector3 a, Vector3 b){
    Vector3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

Vector3 vector3ScalarMult(Vector3 a, double scalar){
    Vector3 result;
    result.x = scalar * a.x;
    result.y = scalar * a.y;
    result.z = scalar * a.z;
    return result;
}

Vector3 vector3Subtraction(Vector3 a, Vector3 b){
    return vector3Addition(a, vector3ScalarMult(b, -1));
}

void printVector3(Vector3 a){
    std::cout << "\nx = ";
    std::cout << a.x;
    std::cout << "\ny = ";
    std::cout << a.y;
    std::cout << "\nz = ";
    std::cout << a.z;
}