#include <iostream>
#include <cstring>
using namespace std;

int f(int x) {
    return sizeof(int);
}

int f(double x) {
    return sizeof(double);
}

struct Structura {
    int a;
    double b;
};

int f(Structura x) {
    return sizeof(Structura);
}

int f(const char* x) {
    return strlen(x);
}

int main() {
    int intValue = 21;
    double doubleValue = 12.33;
    Structura structValue{ 7, 8.5 };
    const char* stringValue = "Lab2 OOP";
    cout << "Size of int: " << f(intValue) << "\n";
    cout << "Size of double: " << f(doubleValue) << "\n";
    cout << "Size of struct: " << f(structValue) << "\n";
    cout << "Length of string: " << f(stringValue) << "\n";
    return 0;
}