#include <iostream>
#include <string>

struct litery {
    std::string a;
    litery(std::string x) {
        a = x;
    }
    auto this_is() -> void {
        std::cout << "wartość a: " << this->a << "\n";
    }
};

int main() {
    litery liczymy("jeden");
    liczymy.this_is();
    std::cout << "wartość a: " << & liczymy.a << "\n";
}
