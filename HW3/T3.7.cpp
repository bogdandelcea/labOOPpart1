#include <iostream>
using namespace std;

class Student {
private:
	static int i;
public:
	Student() {
		i++;
	}
	~Student() {
		i--;
		cout << "deleted ";
	}
	static int getI() {
		return i;
	}
};
int Student::i = 0;
int main() {
	Student student1;
	Student student2;
	Student student3;
	cout << "Number of instances: " << Student::getI() << '\n';
	Student student4;
	cout << "Number of instances: " << Student::getI() << '\n';
	return 0;
}

