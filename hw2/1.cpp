#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector < std::string > res = {};
	std::string t;
	std::getline(std::cin, t);
	std::string word = "";
	std::string s = ".,'\";:?!";
	for (int i = 0; i < t.size(); ++i)
	{
		if (t[i] == ' ') {
			if (!word.empty()) {
				res.push_back(word);
				word = "";
			}
		}
		else if (s.find(t[i]) < std::string::npos) {
			if (!word.empty()) {
				res.push_back(word);
				res.push_back(t[i] + (std::string)"");
				word = "";
			}
			else
			{
				res.push_back(t[i] + (std::string)"");
			}
		}
		else {
			word += t[i];
		}
	}
	if (!word.empty()) {
		res.push_back(word);
	}
	for (int i = 0; i < res.size(); ++i)
	{
		std::cout << res[i] << std::endl;
	}
}