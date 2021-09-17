#include <iostream>
#include <vector>

int main()
{
    std::vector < int > a = { 0,1,2,3,4,6,7,8,9,10 };
    int t = 7;
    int l = 0;
    int r = a.size();
    int m;
    while (l < r) {
        m = floor((l + r) / 2.0);
        if (a[m] < t) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    if (a[l] == t) {
        std::cout << a[l];
    }
    else {
        std::cout << "Not found";
    }
}