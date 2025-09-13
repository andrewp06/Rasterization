#pragma once
#include "3DVector.h"
#include "2DVector.h"
#include <iostream>

struct Triangle3D {
    Vector3 p, q, r;
    void printTriangle();
};

struct Triangle2D {
    Vector2 p, q, r;
    void printTriangle();
    bool pointInTriangle(Vector2 point);
};

Triangle2D project3DTriangle(Triangle3D triangle, Vector3 c, Vector3 theta, Vector3 e);