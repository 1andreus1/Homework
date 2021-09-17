#include <iostream>
#include <vector>

int main()
{
	std::vector < int > a = { 5, 4, 3, 2, 1, 0 };
	for (int i = 1; i < a.size(); ++i)
		for (int j = i; 0 < j && a[j] < a[j-1]; --j)
			std::swap(a[j], a[j-1]);
	for (int i = 1; i < a.size(); ++i)
	{
		std::cout << a[i] << '\n';
	}
}