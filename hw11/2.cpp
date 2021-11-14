#include <iostream>
#include <type_traits>

// remove
template<typename T>
struct remove_const
{
	using type = T;
};

template<typename T>
struct remove_const <const T>
{
	using type = T;
};

template<typename T>
using remove_const_t = typename remove_const<T>::type;

// add
template<typename T>
struct add_const
{
	using type = const T;
};

template<typename T>
using add_const_t = typename add_const<T>::type;

int main() {
	// remove
	std::cout << std::boolalpha << std::is_same_v <int, remove_const_t <int>> << '\n';
	std::cout << std::boolalpha << std::is_same_v <int, remove_const_t <const int>> << '\n';
	std::cout << std::boolalpha << std::is_same_v <const int, remove_const_t <const int>> << '\n';
	std::cout << std::boolalpha << std::is_same_v <double, remove_const_t <const double>> << "\n\n";

	// add
	std::cout << std::boolalpha << std::is_same_v <int, add_const_t <int>> << '\n';
	std::cout << std::boolalpha << std::is_same_v <const int, add_const_t <int>> << '\n';
	std::cout << std::boolalpha << std::is_same_v <double, add_const_t <double>> << '\n';
	std::cout << std::boolalpha << std::is_same_v <const double, add_const_t <double>> << '\n';
}
