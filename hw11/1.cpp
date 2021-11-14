#include <iostream>
#include <type_traits>


template<typename>
struct is_function : std::false_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...)> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) volatile> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const volatile> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...)&> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const&> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) volatile&> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const volatile&> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...)&&> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const&&> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) volatile&&> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const volatile&&> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) volatile noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const volatile noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) & noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const& noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) volatile& noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const volatile& noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) && noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const&& noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) volatile&& noexcept> : std::true_type {};

template<typename RT, typename... Args>
struct is_function<RT(Args...) const volatile&& noexcept> : std::true_type {};

template<typename RT>
inline constexpr bool  is_function_v = is_function<RT>::value;

int main() {
	std::cout << std::boolalpha << is_function_v <int(int)> << '\n';
	std::cout << std::boolalpha << is_function_v <int()> << '\n';
	std::cout << std::boolalpha << is_function_v <void(int)> << '\n';
	std::cout << std::boolalpha << is_function_v <int(int, double)> << '\n';
	std::cout << std::boolalpha << is_function_v <float> << '\n';
}
