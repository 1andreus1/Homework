#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>




int main()
{
	std::vector < std::function < bool(int, int) > > actions = { [](int x, int y) {return y > x; } ,[](int x, int y) {return x > y; } };
	std::vector < int > a = { 1,4,66,44,3,2,7,8,9,0,5,5 };

	std::sort(a.begin(), a.end(), actions[1]);

	for (int i = 0; i < a.size(); ++i)
	{
		std::cout << a[i] << ' ';
	}

	std::cout << "\n";

	std::sort(a.begin(), a.end(), actions[0]);

	for (int i = 0; i < a.size(); ++i)
	{
		std::cout << a[i] << " ";
	}



	return 0;
}