
struct Vector3 {
    double x, y, z;

    void roundTiny(double eps = 1e-6);
    void printVector();
};

Vector3 vector3Addition(Vector3 a, Vector3 b);

Vector3 vector3Subtraction(Vector3 a, Vector3 b);

Vector3 vector3ScalarMult(Vector3 a, double scalar);

void printVector3(Vector3 a);






