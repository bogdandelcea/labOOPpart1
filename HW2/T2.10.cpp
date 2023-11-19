#include <iostream>
using namespace std;

template<typename T>
void swapValues(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

struct Student {
    string name;
    int age;
};

int main() {
    int intA = 5, intB = 10;
    float floatA = 2.5f, floatB = 3.7f;
    Student student1{ "Alina", 20 };
    Student student2{ "Andrei", 21 };
    swapValues(intA, intB);
    swapValues(floatA, floatB);
    swapValues(student1, student2);
    cout << intA << " " << intB;
    cout << '\n';
    cout << floatA << " " << floatB;
    cout << '\n';
    cout << student1.name << student1.age << " " << student2.name << student2.age;
    cout << '\n';
    return 0;
}

//You can create a template function to interchange two values of the same type, including basic types like int, float, double, and even a user-defined struct like Student