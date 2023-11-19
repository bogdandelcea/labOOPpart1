#include <iostream>
#include <cmath>
using namespace std;

float f(float n, bool isRoundedTo100 = false) {
    if (isRoundedTo100) {
        return round(n / 100.0) * 100.0;
    }
    else {
        return round(n);
    }
}

int main() {
    float n = 382.96;
    cout << f(n) << '\n';
    cout << f(n, true) << '\n';
    return 0;
}
