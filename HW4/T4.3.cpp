#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
	string name;
	int grade;
public:
	Student(string name, int grade) {
		this->name = name;
		this->grade = grade;
	}
	string getName() const {
		return name;
	}
	int getGrade() const {
		return grade;
	}
};

class StudentList {
private:
	vector<Student> students;
public:
	void addStudent(const Student& student) {
		students.push_back(student);
	}
	vector<Student> getStudentsWithGrade(int targetGrade) const {
		vector<Student> result;
		for (const auto& student : students) 
			if (student.getGrade() == targetGrade) result.push_back(student);
		return result;
	}
};

int main() {
	StudentList studentList;
	studentList.addStudent(Student("Sami", 5));
	studentList.addStudent(Student("Alex", 4));
	studentList.addStudent(Student("Bogdan", 5));
	studentList.addStudent(Student("Catalin", 3));
	int targetGrade = 5;
	vector<Student> studentsWithGrade5 = studentList.getStudentsWithGrade(targetGrade);
	if (studentsWithGrade5.empty())
		cout << "No students found with grade " << targetGrade << "." << '\n';
	else {
		cout << "Students with grade " << targetGrade << ":" << '\n';
		for (const auto& student : studentsWithGrade5)
			cout << student.getName() << '\n';
	}
	return 0;
}