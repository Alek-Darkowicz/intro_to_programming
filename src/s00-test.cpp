#include <iostream>
#include <string>
int main() {
    int a = 1;
    do {
    a = a + 1;
    std::cout << "ERROR "<< a << "\n";
    } while (a != 15);
    std::cout << "koniec " << a << "\n";
}
