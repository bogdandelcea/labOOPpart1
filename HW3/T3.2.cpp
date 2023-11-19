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
	sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
			if (s1.name != s2.name) {
				return s1.name < s2.name;
			}
			if (s1.age != s2.age) {
				return s1.age < s2.age;
			}
			return s1.grade > s2.grade;
	});
	for (const auto& student : students) {
		std::cout << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << "\n";
	}
	return 0;
}