#include <iostream>
#include <string>
int main(int argc, char* argv[]) {
    if (argc == 0) {
        return 1;
    }
    if ((std::string{argv[1]} == "-l") or (std::string{argv[2]} == "-l")) {
        if ((std::string{argv[1]} == "-r") or (std::string{argv[2]} == "-r")) {
            for (int i=argc-1; i>2; i--) {
            std::cout << argv[i] << "\n";
            }
        }
        else if (std::string{argv[1]} == "-l"){
            for (int i=2; i<argc; i++) {
                std::cout << argv[i] << "\n";
            }
        }
        else {
            for (int i=1; i<argc; i++) {
                std::cout << argv[i] << " ";
            }
            std::cout << "\n";
        }
    }
    else if ((std::string{argv[1]} == "-n") or (std::string{argv[2]} == "-n")) {
        if ((std::string{argv[1]} == "-r") or (std::string{argv[2]} == "-r")) {
            for (int i=argc-1; i>2; i--) {
            std::cout << argv[i] << " ";
            }
        }
        else if (std::string{argv[1]} == "-n") {
            for (int i=2; i<argc; i++) {
            std::cout << argv[i] << " ";
            }
        }
        else {
            for (int i=1; i<argc; i++) {
                std::cout << argv[i] << " ";
            }
            std::cout << "\n";
        }
    }
    else if (std::string{argv[1]} == "-r") {
        for (int i=argc-1; i>1; i--) {
            std::cout << argv[i] << " ";
        }
        std::cout << "\n";
    }
    else {
        for (int i=1; i<argc; i++) {
            std::cout << argv[i] << " ";
        }
        std::cout << "\n";
    }
}
