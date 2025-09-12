#include "3DVector.cpp"
#include "2DVector.cpp"
#include <cmath>
#include <iostream>
using namespace std;

/*
    a  -  the 3D position of a point A that is to be projected
    c  -  the 3D position of a point C representing the camera
    theta  -  The orientation of the camera (represented by Tait–Bryan angles)

*/
Vector3 solveForD(Vector3 a, Vector3 c, Vector3 theta){
    //we define the vector D as the position of point A with respect to the cordnate system defined by the camera
    Vector3 d;

    // difference vector is the difference bettween vectors a and c
    Vector3 difference = vector3Subtraction(a,c);

    d.x = cos(theta.y)*(sin(theta.z) * difference.y + cos(theta.z) * difference.x) - sin(theta.y) * difference.z;

    d.y = sin(theta.x) * (cos(theta.y) * difference.z + sin(theta.y) * (sin(theta.z) * difference.y + cos(theta.z) * difference.x)) 
        + cos(theta.x) * (cos(theta.z) * difference.y - sin(theta.z) * difference.x);

    d.z = cos(theta.x) * (cos(theta.y) * difference.z + sin(theta.y) * (sin(theta.z) * difference.y + cos(theta.z) * difference.x))
         - sin(theta.x) * (cos(theta.z) * difference.y - sin(theta.z) * difference.x);

    d.roundTiny();

    return d;
}

/*
    d  -  position of point A with respect to the cordnate system defined by the camera
    e  -   the display surface's position relative to aforementioned c.  Usually (0, 0, f) where f is the focal length of the camera to the screen
*/
Vector2 solveForB(Vector3 d, Vector3 e){
    //We define vector b as the 2D projeciton of a
    Vector2 b;

    b.x = e.z / d.z * d.x + e.x;
    b.y = e.z / d.z * d.y + e.y;

    b.roundTiny();

    return b;
}

int main(){
    Vector3 c = {0, 0, 0};
    Vector3 a = {0, 0, 10};
    Vector3 e = {0,0,5};
    Vector3 theta = {M_PI/4, 0, 0};
    Vector3 d = solveForD(a, c, theta);
    d.printVector();
    Vector2 result = solveForB(d, e);
    result.printVector();
}