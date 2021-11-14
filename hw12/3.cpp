#include <iostream>


constexpr double get_e(int members) {
	double res = 1;
	double den = 1;
	for (int i = 1; i < members; i++) {
		den = den * i;
		res = res + 1 / den;
	}
	return res;
}

int main() {
	constexpr double res = get_e(20);
	std::cout << res << '\n';
}
