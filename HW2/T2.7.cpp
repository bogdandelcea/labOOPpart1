#include <iostream>
#include <cmath>
using namespace std;

struct nrComplex {
    float a; 
    float b; 
};

float absoluteValue(float x) {
    return abs(x);
}

float absoluteValue(nrComplex complexNumber) {
    return sqrt(complexNumber.a * complexNumber.a + complexNumber.b * complexNumber.b);
}

int main() {
    float realNumber = -5.96;
    nrComplex complexNumber = { 3.0, -3.0 };

    cout << "Absolute value of real number: " << absoluteValue(realNumber) << '\n';
    cout << "Absolute value of complex number: " << absoluteValue(complexNumber) << '\n';

    return 0;
}