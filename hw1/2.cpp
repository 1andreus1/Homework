#include <iostream>
#include <iomanip>
std::string s, v;
double a;
const double L = 1e2, W = 1e3, F = 1e5;


int main() {
    std::cout << "Select the base system: SI or CGS\n";
    std::cin >> s;
    if (s == "SI") {
        std::cout << "Select a value: Length (m), Weight (kg), Force (n)\n";
        std::cin >> v;
        std::cout << "Enter a number:\n";
        std::cin >> a;
        if (v == "Length") {
            std::cout << a * L << " sm";
        }
        else if (v == "Weight") {
            std::cout << a * W << " g";
        }
        else {
            std::cout << a * F << " dyn";
        }
    }
    else {
        std::cout << "Select a value: Length (sm), Weight (g), Force (dyn)\n";
        std::cin >> v;
        std::cout << "Enter a number:\n";
        std::cin >> a;
        if (v == "Length") {
            std::cout << a / L << " m";
        }
        else if (v == "Weight") {
            std::cout << a / W << " kg";
        }
        else {
            std::cout << a / F << " n";
        }
    }

    return 0;
}

