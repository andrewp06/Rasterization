struct Vector2 {
    double x, y;

    void roundTiny(double eps = 1e-6);
    void printVector();
    
};

Vector2 vector2Addition(Vector2 a, Vector2 b);

Vector2 vector2Subtraction(Vector2 a, Vector2 b);

Vector2 vector2ScalarMult(Vector2 a, double scalar);

double dotProduct2(Vector2 a, Vector2 b);

void printVector2(Vector2 a);






