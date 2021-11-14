#include <iostream>
#include <type_traits>


template <bool C, typename RT>
struct enable_if
{
	using type = RT;
};

template <typename RT>
struct enable_if <false, RT>
{

};

template < bool C, typename RT = typename void>
using enable_if_t = typename enable_if <C, RT>::type;


int main() {
	std::cout << std::boolalpha << std::is_same_v <int, enable_if_t <true, int>> << '\n';
	std::cout << std::boolalpha << std::is_same_v <int, enable_if_t <true, float>> << '\n';
	std::cout << std::boolalpha << std::is_same_v <void, enable_if_t <true>> << '\n';
	//std::cout << std::boolalpha << std::is_same_v <void, enable_if_t <false>> << '\n'; Здесь ошибка(SFINAE)
}
