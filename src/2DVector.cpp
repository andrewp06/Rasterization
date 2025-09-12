#include "2DVector.h"
#include <iostream>

#include <cmath>

struct Vector2;


void Vector2::roundTiny(double eps) {
    if (std::abs(x) < eps) x = 0.0;
    if (std::abs(y) < eps) y = 0.0;

}

void Vector2::printVector(){
    std::cout << "(" << x << "," << y << ")\n";
}



Vector2 vector2Addition(Vector2 a, Vector2 b){
    Vector2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Vector2 vector2ScalarMult(Vector2 a, double scalar){
    Vector2 result;
    result.x = scalar * a.x;
    result.y = scalar * a.y;
    return result;
}

Vector2 vector2Subtraction(Vector2 a, Vector2 b){
    return vector2Addition(a, vector2ScalarMult(b, -1));
}