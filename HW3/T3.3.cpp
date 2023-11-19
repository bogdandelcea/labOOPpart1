#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int age;
	double grade;
	Student(string name, int age, double grade) {
		this->name = name;
		this->age = age;
		this->grade = grade;
	}
};

int main() {
	vector<Student> students = {
		{"Alex", 20, 8.7},
		{"Marta", 22, 4.9},
		{"Cata", 19, 5.0},
		{"Rares", 21, 7.6},
	};
	auto searchStudentByName = [&students](const string& targetName) {
		auto it = find_if(students.begin(), students.end(),
			[targetName](const Student& student) {
				return student.name == targetName;
			});
		return it != students.end() ? &(*it) : nullptr;
	};
	string targetName = "Marta";
	Student* foundStudent = searchStudentByName(targetName);
	if (foundStudent != nullptr) cout << "Student found!\n";
	else cout << "Student not found.\n";
	return 0;
}