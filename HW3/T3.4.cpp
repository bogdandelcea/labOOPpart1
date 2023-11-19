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

vector<Student> findStudents(const vector<Student>& students) {
	double highestGrade = max_element(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
		return s1.grade < s2.grade;
		})->grade;
	vector<Student> highestGradeStudents;
	copy_if(students.begin(), students.end(), back_inserter(highestGradeStudents), [highestGrade](const Student& student) {
		return student.grade == highestGrade;
		});
	return highestGradeStudents;
}

int main() {
	vector<Student> students = {
		{"Alex", 20, 8.7},
		{"Marta", 22, 4.9},
		{"Cata", 19, 8.7},
		{"Rares", 21, 7.6},
	};
	vector<Student> highestGradeStudents = findStudents(students);
	if (!highestGradeStudents.empty()) {
		cout << "Students with the highest grade:\n";
		for (const auto& student : highestGradeStudents) {
			std::cout << "Name: " << student.name << ", Grade: " << student.grade << "\n";
		}
	}
	else {
		std::cout << "No students found.\n";
	}
	return 0;
}