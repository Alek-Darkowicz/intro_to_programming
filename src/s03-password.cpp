#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc == 0) {
        return 1;
    }
    auto const password = std::string{argv[1]};
    auto proba = std::string{};
    while (password != proba) {
        std::cout << "password:";
        std::getline(std::cin, proba);
    } 
    std::cout << "ok!\n";
    return 0;
}

