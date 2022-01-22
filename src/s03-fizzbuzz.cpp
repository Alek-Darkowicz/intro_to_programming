#include <iostream>
#include <string>
int main(int argc, char* argv[]) {
    if (argc == 0) {
        return 1;
        }
    int a = std::stoi(argv[1]);
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
        }
    
}
