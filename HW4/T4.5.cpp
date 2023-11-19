#include <iostream>
#include <string>
using namespace std;

class Class {
private:
    int* intSize;
    string* strPtr;
public:
    void initializeMembers() {
        intSize = new int(10);
        strPtr = new string("Laborator OOP!");
    }
    void displayMembers() {
        cout << "Integer value: " << *intSize << '\n';
        cout << "String value: " << *strPtr << '\n';
    }
    ~Class() {
        delete intSize;
        delete strPtr;
    }
};

int main() {
    Class obj;
    obj.initializeMembers();
    obj.displayMembers();
    return 0;
}

//When members of a class are pointers,
//pseudo-constructors can be used to allocate memory dynamically and initialize these pointers to point to valid objects.