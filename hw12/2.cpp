#include <iostream>
#include <type_traits>


template<int n>
struct Fib
{
	static const int value = Fib<n - 1>::value + Fib<n - 2>::value;
};

template<>
struct Fib<0>
{
	static const int value = 0;
};

template<>
struct Fib<1>
{
	static const int value = 1;
};



int main() {
	constexpr int res = Fib<7>::value;
	std::cout << res << '\n';
}