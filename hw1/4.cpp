#include <iostream>
int a = 1, b = 2;

int main() {
	a = a + b;
	b = a - b;
	a = a - b;
	std::cout<<a<<' '<<b;
	return 0;
}