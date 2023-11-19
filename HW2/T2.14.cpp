#include <iostream>
#include <stdexcept>
using namespace std;

double solveLinearEquation(double a, double b) {
    if (a == 0.0) {
        throw invalid_argument("Coefficient 'a' must be non-zero for a linear equation.");
    }
    return -b / a;
}

int main() {
    try {
        double a = 2.0, b = -6.0;
        double solution = solveLinearEquation(a, b);
        cout << "Solution: x = " << solution << '\n';
        a = 0.0;
        solution = solveLinearEquation(a, b);
        a = 0.0;
        b = 0.0;
        solution = solveLinearEquation(a, b);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}