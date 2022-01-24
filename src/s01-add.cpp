#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 0) {
        return 1;
    }
    auto const a = std::stol(argv[1]);
    auto const b = std::stol(argv[2]);
    std::cout << (a + b) << "\n";
    return 0;
}
