#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double real, double imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    Complex multiply(const Complex& other) const {
        double resultReal = (real * other.real) - (imaginary * other.imaginary);
        double resultImaginary = (real * other.imaginary) + (imaginary * other.real);
        return Complex(resultReal, resultImaginary);
    }
    void display() const {
        cout << real << " + " << imaginary << 'i' << '\n';
    }
};

int main()
{
    Complex n1(4, 7);
    Complex n2(5, -2);
    Complex sum = n1.add(n2);
    Complex prod = n1.multiply(n2);
    cout << "Sum: ";
    sum.display();
    cout << "Product: ";
    prod.display();
    return 0;
}

