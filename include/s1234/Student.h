#include <iostream>
#include <string>

struct student {
    std::string name;
    std::string surname;
    std::string index;
    short semester;
    double average;
    //constructor
    student(std::string a, std::string b, std::string c, short d, double e) {
        name = a;
        surname = b;
        index = c;
        semester = d;
        average = e;
    }
    //member function
    auto to_string() const -> std::string {
        return ("Name: " + name + "\nSurname: " + surname + "\nIndex number: " + index + "\nCurrent semester: " + std::to_string(semester) + "\nCurrent average: " + std::to_string(average) + "\n");
    }
};
