#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
public:
    Rectangle(double length, double width) {
        this->length = length;
        this->width = width;
    }
    double calculatePerimeter() {
        return 2 * (length + width);
    }
    double calculateArea() {
        return length * width;
    }
};

int main() {
    Rectangle rectangle1(5, 8);
    Rectangle rectangle2(4, 6);
    double perimeter1 = rectangle1.calculatePerimeter();
    double area1 = rectangle1.calculateArea();
    double perimeter2 = rectangle2.calculatePerimeter();
    double area2 = rectangle2.calculateArea();
    if (perimeter1 > perimeter2) cout << "Perimeter1 is greater " << '\n';
    else if (perimeter2 > perimeter1) cout << "Perimeter2 is greater " << '\n';
    else cout << "Perimeters are equal " << '\n';
    if (area1 > area2) cout << "Area1 is greater " << '\n';
    else if (area2 > area1) cout << "Area2 is greater " << '\n';
    else cout << "Areas are equal " << '\n';
    return 0;
}
