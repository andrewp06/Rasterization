#pragma once

#include "3DVector.h"
#include "2DVector.h"
#include "Color.h"
#include <iostream>

struct Triangle2D {
    Vector2 p, q, r;
    Color color;
    void printTriangle();
    bool pointInTriangle(Vector2 point);
    Vector2 maxXY();
    Vector2 minXY();
};

struct Triangle3D {
    Vector3 p, q, r;
    Color color;
    void printTriangle();
    Triangle2D project3DTriangle(Vector3 c, Vector3 theta, Vector3 e);
};