#include <iostream>
#include <string>
using namespace std;

class Driver {
private:
	string name;
	string licenseNumber;
public:
	Driver(){}
	Driver(string name, string licenseNumber) {
		this->name = name;
		this->licenseNumber = licenseNumber;
	}
};

enum class DocumentType {
	REGISTRATION,
	INSURANCE,
	LICENSE
};

class Documents {
private:
	bool registration;
	bool insurance;
	bool license;
public:
	Documents() {
		registration = false;
		insurance = false;
		license = false;
	}
	void provideDocument(DocumentType type) {
		switch (type) {
			case DocumentType::REGISTRATION:
				registration = true;
				break;
			case DocumentType::INSURANCE:
				insurance = true;
				break;
			case DocumentType::LICENSE:
				license = true;
				break;
		}
	}
	bool areAllDocumentsProvided() {
		return (registration && insurance && license);
	}
};

class Car {
private:
	string make;
	string model;
	string plateNumber;
	Driver driver;
public:
	Car(string make, string model, string plateNumber, Driver driver) {
		this->make = make;
		this->model = model;
		this->plateNumber = plateNumber;
		this->driver = Driver(driver);
	}
	string getMake() {
		return make;
	}

	string getModel() {
		return model;
	}

	string getPlateNumber() {
		return plateNumber;
	}

	Driver getDriver() {
		return driver;
	}
};

int main() {
	Driver driver("Bogdan Delcea", "DOLJCRAIOVA");
	Car car("Skoda", "Octavia2", "DJ07DLC", driver);
	Documents carDocuments;
	carDocuments.provideDocument(DocumentType::REGISTRATION);
	carDocuments.provideDocument(DocumentType::INSURANCE);
	carDocuments.provideDocument(DocumentType::LICENSE);
	if (carDocuments.areAllDocumentsProvided()) {
		cout << "All required documents are provided. Verification successful!" << '\n';
	}
	else {
		cout << "Some documents are missing. Verification failed." << '\n';
	}
	return 0;
}