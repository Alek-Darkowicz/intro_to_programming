#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc == 0) {
        return 1; 
        }
    for (auto i = std::stoi(argv[1]); i > -1; --i) {
    std::cout << i << "...\n";
    }
}
