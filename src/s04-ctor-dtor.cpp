#include <iostream>
#include <string>

struct litery {
    std::string a;
    std::string b; 
    std::string c;
    litery(std::string x, std::string y, std::string z) {
        a = x;
        b = y;
        c = z;
    }
    ~litery() {
        std::cout << "DESTRUCTION! " << a << " " << b << " " << c << "\n";
    }
};

int main() {
    litery liczymy("jeden", "dwa", "czy");
}
