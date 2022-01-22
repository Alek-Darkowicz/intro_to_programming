#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    auto const a = std::stol(argv[1]);
    auto const b = std::stol(argv[2]);
    std::cout << (a + b) << "\n" << argc << " bo musi być użyte argc\n";
    return 0;
}
