#include <iostream>
#include <cmath>

int main() {
    double a, b, c, d, eps = std::numeric_limits <double> ::epsilon();
    std::cout << "Enter a b c\n";
    std::cin >> a >> b >> c;
    if (abs(a - 0) < eps) {
        if (abs(b - 0) < eps) {
            if (abs(c - 0) < eps) {
                std::cout << "Endless number of solutions";
            }
            else {
                std::cout << "No solutions";
            }
        }
        else {
            std::cout << -c / b;
        }
    }
    else {
        d = b * b - 4.0 * a * c;
        if (abs(d - 0) < eps) {
            std::cout << (-b + sqrt(d)) / 2.0 / a;
        }
        else if (d < 0) {
            std::cout << "No solutions";
        }
        else {
            std::cout << (-b + sqrt(d)) / 2.0 / a << "\n";
            std::cout << (-b - sqrt(d)) / 2.0 / a;
        }
    }


    return 0;
}