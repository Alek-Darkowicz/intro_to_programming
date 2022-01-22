#include <random>
#include <iostream>
#include <string>
auto ask() -> int
{
    std::cout << "guess:";
    auto n = std::string{};
    std::getline(std::cin, n);
    return std::stoi(n);
}
int main() {
    std::random_device rd;
    std::uniform_int_distribution<int> d100 (1, 100);
    auto const guess = d100(rd);
    int a = int{};
    do  {
        int a = ask();
        if (guess == a) {
            std::cout << "just right!\n";
        break;
        }
        else if (guess < a) {
            std::cout << "too big!\n";
        }
        else if (guess > a) {
            std::cout << "too small!\n";
        } 
        } while (guess != a);
}
