#include <iostream>
using namespace std;

class A {
public:
    int aa;
protected:
    int ab;
private:
    int ac;
public:
    void testA() {
        aa = 1;
        ab = 2;
        ac = 3;
    }
    void accessAb() {
        cout << "ab: " << ab << '\n';
    }
};

class B : public A {
public:
    int ba;
protected:
    int bb;
private:
    int bc;
public:
    void testB() {
        ba = 4;
        bb = 5;
        aa = 6; // Public member of A
        ab = 7; // Protected member of A
        // ac = 8; // Private member of A (inaccessible)
    }
    void accessBb() {
        cout << "bb: " << bb << '\n';
    }
};

class C : public B {
public:
    int ca;
protected:
    int cb;
private:
    int cc;
public:
    void testC() {
        ca = 9;
        cb = 10;
        aa = 11; // Public member of A
        ab = 12; // Protected member of A
        // ac = 13; // Private member of A (inaccessible)
        // ba = 14; // Public member of B (inaccessible due to protected inheritance)
        // bb = 15; // Protected member of B (inaccessible due to protected inheritance)
        // bc = 16; // Private member of B (inaccessible)
    }
    void accessCb() {
        cout << "cb: " << cb << '\n';
    }
};

int main() {
    C clasa;
    clasa.testC();
    clasa.testB();
    clasa.testA();
    cout << "aa: " << clasa.aa << '\n';
    cout << "ba: " << clasa.ba << '\n';
    cout << "ca: " << clasa.ca << '\n';
    clasa.accessAb();
    clasa.accessBb();
    clasa.accessCb();
    return 0;
}
