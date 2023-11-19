#include <iostream>
#include <string>
using namespace std;

class Driver {
public:
    string name;
    Driver(){}
    Driver(string name) {
        this->name = name;
    }
    string getName(){
        return name;
    }
};

class Car {
public:
    int age;
    Driver driver;
    Car(int age, Driver driverName) {
        this->age = age;
        this->driver = Driver(driverName);
    }
    void exchangeDrivers(Car& otherCar) {
        Driver tempDriver = otherCar.driver;
        otherCar.driver = this->driver;
        this->driver = tempDriver;
    }

    void displayDriverName() {
        cout << "Driver's name: " << driver.getName() << '\n';
    }
};

int main() {
    Driver driver1("Marius");
    Driver driver2("Catalin");

    Car car1(7, driver1);
    Car car2(10, driver2);
    cout << "Car 1's ";
    car1.displayDriverName();
    cout << "Car 2's ";
    car2.displayDriverName();
    car1.exchangeDrivers(car2);

    cout << "\nAfter exchanging drivers:\n";
    cout << "Car 1's ";
    car1.displayDriverName();
    cout << "Car 2's ";
    car2.displayDriverName();

    return 0;
}
