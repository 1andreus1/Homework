#include <iostream>
#include <iomanip>

int main() {
    std::string name;
    int price, temperature;
    bool hasCashback;
    std::cout << "Product's name: ";
    std::cin >> name;
    std::cout << "Product's price: ";
    std::cin >> price;
    std::cout << "Is cash-back available for this product? (true/false) ";
    std::cin >> std::boolalpha >> hasCashback;
    std::cout << "Maximum storing temperature: ";
    std::cin >> temperature;

    std::cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    std::cout << name << '\n';
    std::cout << std::setw(17) << std::setfill('.') << std::left << "Price:" << std::right << std::uppercase << std::hex << std::setfill('0') << std::setw(8) << price << '\n';
    std::cout << "Has cash-back:" << std::setw(11) << std::setfill('.') << std::boolalpha << hasCashback << std::dec << '\n';
    std::cout << "Max temperature:" << std::setw(9) << std::setfill('.') << std::boolalpha << std::showpos << temperature << '\n';

    return 0;
}