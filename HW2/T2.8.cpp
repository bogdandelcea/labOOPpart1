#include <iostream>
using namespace std;

float maxOfThree(float a, float b, float c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int main(){
    float three = maxOfThree(2.5, 1.8, 3.0);
    cout << "Max : " << three << '\n';
    return 0;
}

