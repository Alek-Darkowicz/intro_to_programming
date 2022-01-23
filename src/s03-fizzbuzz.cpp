#include <iostream>
#include <string>
int main(int argc, char* argv[]) {
    if (argc == 0) {
        return 1;
        }
    int argument = std::stoi(argv[1]);
for (int a=argument; a>0; a--) {
    if (a % 15 == 0) {
        std::cout << a << " FizzBuzz\n";
        }
    else {
        if (a % 3 == 0) {
            std::cout << a << " Fizz\n";
        }
        else if (a % 5 == 0) {
            std::cout << a << " Buzz\n";
        }
        else {
            std::cout << a << "\n";
        }
    }
}  
}
