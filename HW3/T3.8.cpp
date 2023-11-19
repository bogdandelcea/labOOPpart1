#include <iostream>
#include <cmath>
using namespace std;

void solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Two distinct real solutions:\n";
        cout << "Root 1: " << root1 << "\n";
        cout << "Root 2: " << root2 << "\n";
    }
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "One real solution (repeated root):\n";
        cout << "Root: " << root << "\n";
    }
    else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Two complex conjugate solutions:\n";
        cout << "Root 1: " << realPart << " + " << imaginaryPart << "i\n";
        cout << "Root 2: " << realPart << " - " << imaginaryPart << "i\n";
    }
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    solveQuadratic(a, b, c);
    return 0;
}
