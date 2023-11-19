#include <iostream>
#include <cstring>
using namespace std;

typedef int (*ptropr)(int, int);

int addition(int a, int b) {
    return a + b;
}

int subtraction(int a, int b) {
    return a - b;
}

int main() {
    int x, y;
    char op;
    cin >> x >> op >> y;
    ptropr semn;
    if (op == '+') {
        semn = addition;
    }
    else if (op == '-') {
        semn = subtraction;
    }
    else {
        cout << "Invalid operation. Please enter + or -." << '\n';
        return 0;
    }
    int res = semn(x, y);
    cout << res;
    return 0;
}