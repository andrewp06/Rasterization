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

bool Triangle2D::pointInTriangle(Vector2 point){

    Vector2 v0 = vector2Subtraction(r, p);
    Vector2 v1 = vector2Subtraction(q, p);
    Vector2 v2 = vector2Subtraction(point, p);

    double dot00 = dotProduct2(v0,v0);
    double dot01 = dotProduct2(v0,v1);
    double dot02 = dotProduct2(v0,v2);
    double dot11 = dotProduct2(v1,v1);
    double dot12 = dotProduct2(v1,v2);

    double invDenom = 1 / ((dot00 * dot11) - (dot01 * dot01));

    double u = ((dot11 * dot02) - (dot01 * dot12)) * invDenom;
    double v = ((dot00 * dot12) - (dot01 * dot02)) * invDenom;

    bool result = u >= 0;
    result &= v >= 0;
    result &= (v + u) <=1;

    return result;    
}


int main(){
    Triangle2D triangle2 = {{0, 0}, {4, 0}, {0, 3}};
    std::cout << "inside: " << triangle2.pointInTriangle({1, 1});
    std::cout << "\noutside: " << triangle2.pointInTriangle({2, 2});
    std::cout << "\nOutside: " << triangle2.pointInTriangle({4, 3});
    std::cout << "\nVertex: " << triangle2.pointInTriangle({0, 0});
    std::cout << "\nEdge: " << triangle2.pointInTriangle({2, 0});
}
