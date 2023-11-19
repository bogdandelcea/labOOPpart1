#include <iostream>
using namespace std;

void interchangeWithReferences(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void interchangeWithPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << x << " " << y << '\n';
    cout << "After references ";
    interchangeWithReferences(x, y);
    cout << x << " " << y << '\n';
    x = 5;
    y = 10;
    cout << "Before ";
    interchangeWithPointers(&x, &y);
    cout << "After references ";
    cout << x << " " << y << '\n';
    return 0;
}
    
