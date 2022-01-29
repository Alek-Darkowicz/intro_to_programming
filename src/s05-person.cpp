#include <iostream>
#include <string>

class Person {
    public:
    std::string Name;
    Person(std::string a) {
        Name = a;
    }
    virtual auto to_string() -> std::string = 0;
    //who_is_it(Person const&) -> std::string {
       // return ()
    //}
};
class Mr : Person {
    auto to_string() -> std::string override{
        return ("Mr" + Name);
    }
};
class Mrs : Person {
    auto to_string() -> std::string override{
        return ("Mrs" + Name);
    }
};
class King : Person {
    auto to_string() -> std::string override{
        return ("King" + Name);
    }
};
class Queen : Person {
    auto to_string() -> std::string override{
        return ("Queen" + Name);
    }
};

int main() {
    Person this.s25438("Aleksander Darkowicz");
    std::cout << s25438.to_string();
}
