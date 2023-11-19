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
	string getName() const{
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
	Student getStudentWithMaxGrade() const {
		if (students.empty()) {
			return Student("", 0);
		}
		auto maxGradeStudent = max_element(students.begin(), students.end(),
			[](const Student& a, const Student& b) {
				return a.getGrade() < b.getGrade();
			});
		return *maxGradeStudent;
	}
};

int main() {
	StudentList studentList;
	studentList.addStudent(Student("Marian", 95));
	studentList.addStudent(Student("Robert", 87));
	studentList.addStudent(Student("Anna-Maria", 92));
	studentList.addStudent(Student("Sorina", 100));
	Student maxGradeStudent = studentList.getStudentWithMaxGrade();
	cout << "Student with maximum grade: " << maxGradeStudent.getName() << " (Grade: " << maxGradeStudent.getGrade() << ")" << '\n';
	return 0;
}

// The getStudentWithMaxGrade method is placed in the StudentList class.