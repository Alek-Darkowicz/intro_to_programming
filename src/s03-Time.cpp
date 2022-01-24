#include <iostream>
#include <string>
#include "s1234/Time.h"

int main() {
    time_ now(23, 59, 59);
    time_ tomorrow(0, 30, 0);
    time_ shift(0, 70, 12);
    now.next_hour();
    std::cout << "\n";
    now.next_second();
    std::cout << "\n";
    now.next_minute();
    std::cout << "\n";
    std::cout << now.to_string(now.time_of_day()) << "\n";
    auto dodane = now + shift;
    std::cout << dodane.to_string() << "\n";
    auto odjete = now - shift;
    std::cout << odjete.to_string() << "\n";
    if ((now < tomorrow) == true) {
        std::cout << now.to_string() << " < " << tomorrow.to_string() << "\n";
    }
    else {
        std::cout << "< is false\n";
    }
    if ((now > tomorrow) == true) {
        std::cout << now.to_string() << " > " << tomorrow.to_string() << "\n";
    }
    else {
        std::cout << "> is false\n";
    }
    if ((now == tomorrow) == true) {
        std::cout << now.to_string() << " == " << tomorrow.to_string() << "\n";
    }
    else {
        std::cout << "== is false\n";
    }
    if ((now != tomorrow) == true) {
        std::cout << now.to_string() << " != " << tomorrow.to_string() << "\n";
    }
    else {
        std::cout << "!= is false\n";
    }
    std::cout << now.count_seconds() << " seconds\n";
    std::cout << now.count_minutes() << " minutes\n";
    auto ttm = now.time_to_midnight();
    std::cout << ttm.to_string() << "\n";
}
