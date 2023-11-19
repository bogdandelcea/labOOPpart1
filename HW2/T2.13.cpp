#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

bool compareByAgeDesc(const Person& a, const Person& b) {
    return a.age > b.age;
}

int main() {
    vector<Person> people = {
        {"Alina", 25},
        {"Bogdan", 30},
        {"Cristi", 22},
        {"David", 35},
        {"Evelina", 28}
    };
    sort(people.begin(), people.end(), compareByAgeDesc);
    for (const auto& person : people) {
        cout << "Name: " << person.name << ", Age: " << person.age << " years old\n";
    }
    return 0;
}