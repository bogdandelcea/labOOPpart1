#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	double grade;
};

Student Max(const Student& student1, const Student& student2) {
	return (student1.grade > student2.grade) ? student1 : student2;
}

int main() {
	Student student1{ "Alice", 90.5 };
	Student student2{ "Bob", 85.0 };
	Student maxStudent = Max(student1, student2);
	cout << "Student with highest grade: " << maxStudent.name << " " << maxStudent.grade << "\n";
	return 0;
}
