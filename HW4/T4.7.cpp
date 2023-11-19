#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Address {
private:
	string streetAddress;
	string city;
	string postalCode;
public:
	Address(){}
	Address(string streetAddress, string city, string postalCode) {
		this->streetAddress = streetAddress;
		this->city = city;
		this->postalCode = postalCode;
	}
	string getAddress() {
		return this->streetAddress;
	}
	string getCity() {
		return this->city;
	}
	string getPostalCode() {
		return this->postalCode;
	}
};

class Engine {
private:
	int horsepower;
	string fuelType;
public:
	Engine(){}
	Engine(int horsepower, string fuelType) {
		this->horsepower = horsepower;
		this->fuelType = fuelType;
	}
	int getHorsepower() {
		return this->horsepower;
	}

	string getFuelType() const {
		return this->fuelType;
	}
};

class Car {
protected:
	string make;
	string model;
	Engine engine;
public:
	Car(string make, string model, Engine engine) {
		this->make = make;
		this->model = model;
		this->engine = Engine(engine);
	}
	string getMake() {
		return this->make;
	}

	string getModel() {
		return this->model;
	}

	Engine getEngine() {
		return this->engine;
	}

	void startEngine() {
		cout << "Engine started!" << '\n';
	}

	void stopEngine() {
		cout << "Engine stopped!" << '\n';
	}
};

class Driver {
private:
	string name;
	int age;
public:
	Driver(){}
	Driver(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
};

class Commuter {
private:
	string name;
	Address address;
public:
	Commuter(string name, Address address) {
		this->name = name;
		this->address = Address(address);
	}
	string getName() {
		return name;
	}

	Address getAddress() {
		return address;
	}
};

class Mosquito {
private:
	string species;
	bool isBloodSucker;
public:
	Mosquito(string species, bool isBloodSucker) {
		this->species = species;
		this->isBloodSucker = isBloodSucker;
	}
	string getSpecies() {
		return this->species;
	}
	bool getIsBloodSucker() {
		return this->isBloodSucker;
	}
};

class BusStation {
private:
	string name;
	Address address;
public:
	BusStation(){}
	BusStation(string name, Address address) {
		this->name = name;
		this->address = Address(address);
	}
	string getName(){
		return this->name;
	}
	Address getAddress() {
		return this->address;
	}
};

class Bus : public Car {
private:
	string plateNumber;
	BusStation currentLocation;
	Driver driver;
	vector<Commuter> passengers;
public:
	Bus(string busMake, string busModel, Engine engine, string plate, BusStation location, Driver busDriver): Car(busMake, busModel, engine) {
		this->plateNumber = plate;
		this->currentLocation = location;
		this->driver = busDriver;
	}
	string getPlateNumber() {
		return this->plateNumber;
	}
	BusStation getCurrentLocation() {
		return this->currentLocation;
	}
	Driver getDriver() {
		return this->driver;
	}
	vector<Commuter> getPassengers() {
		return this->passengers;
	}
	void loadPassenger(Commuter passenger) {
		passengers.push_back(passenger);
	}
};

int main() {
	Address busStationAddress("Strada Toporasi", "Craiova", "200246");
	BusStation myBusStation("Statia Olimp", busStationAddress);
	Engine busEngine(300, "Diesel");
	Driver busDriver("Aurel Controloru", 35);
	Bus myBus("Mercedes", "Sprinter", busEngine, "DJ88RAT", myBusStation, busDriver);
	myBus.startEngine();
	Address commuterAddress("Cornitoiu", "Craiovita", "200294");
	Commuter myCommuter("Bogdan Delcea", commuterAddress);
	myBus.loadPassenger(myCommuter);
	vector<Commuter> busPassengers = myBus.getPassengers();
	cout << "Passengers on the bus:\n";
	for (auto& passenger : busPassengers) {
		cout << "Name: " << passenger.getName() << ", Address: " << passenger.getAddress().getAddress() << '\n';
	}
	return 0;
}