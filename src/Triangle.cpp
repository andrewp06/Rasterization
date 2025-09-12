#include "Triangle.h"
#include "ProjectionMath.h"
#include <iostream>

void Triangle3D::printTriangle() {
    std::cout << "\n3D Triangle\n";
    p.printVector();
    q.printVector();
    r.printVector();
}

void Triangle2D::printTriangle() {
    std::cout << "\n2D Triangle\n";
    p.printVector();
    q.printVector();
    r.printVector();
}

Triangle2D project3DTriangle(Triangle3D triangle3, Vector3 c, Vector3 theta, Vector3 e){
    Triangle2D triangle2;
    triangle2.p = solve2DProjection(triangle3.p, c, theta, e);
    triangle2.q = solve2DProjection(triangle3.q, c, theta, e);
    triangle2.r = solve2DProjection(triangle3.r, c, theta, e);

    return triangle2;
}


int main(){
    Triangle3D triangle3 = {{1,1,5}, {-1, 1, 5}, {0, -1, 5}};
    triangle3.printTriangle();
    Vector3 c = {0, 0, 0};
    Vector3 e = {0,0,5};
    Vector3 theta = {0, 0, 0};
    Triangle2D triangle2 = project3DTriangle(triangle3, c, theta, e);
    triangle2.printTriangle();
}
