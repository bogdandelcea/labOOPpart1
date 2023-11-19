#include <iostream>
#include <string>
using namespace std;

struct Cat {
	string masterName;
	int age;
};

struct Person {
	string name;
	int age;
};

template <typename T>
T minAge(const T& a, const T& b) {
	return (a.age < b.age) ? a : b;
}

template <typename T, typename U>
auto minAge(const T& a, const U& b) {
	return (a.age < b.age) ? a : b;
}


template <typename T>
bool sameAge(const T& a, const T& b) {
	return a.age == b.age;
}

template <typename T, typename U>
bool sameAge(const T& a, const U& b) {
	return a.age == b.age;
}

int main() {
	Cat cat1{ "Garfield", 3 };
	Cat cat2{ "Tom", 2 };
	Cat minCat = minAge(cat1, cat2);
	cout << "Cat with min age: " << minCat.masterName << " " << minCat.age << '\n';
	bool sameCatAge = sameAge(cat1, cat2);
	cout << "Cats have the same age: " << boolalpha << sameCatAge << "\n\n";

	Person om{ "Bogdan", 20 };
	auto minEntity = minAge(cat1, om);
	cout << "Entity with minimum age: ";
	if (minEntity.age == cat1.age)
		cout << minEntity.masterName << " " << minEntity.age << '\n';
	else if (minEntity.age == om.age) cout << minEntity.masterName << " " << minEntity.age << '\n';
	bool entitiesSameAge = sameAge(cat1, om);
	cout << "Entities have the same age: " << boolalpha << entitiesSameAge << "\n\n";

	return 0;
}