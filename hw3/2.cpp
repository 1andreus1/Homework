#include <iostream>
#include <vector>

void MergeSort(std::vector <int>& x, int l, int r) {

    if (l == r) {
        return;
    }
    else if (r - l == 1) {
        if (x[l] > x[r]) {
            std::swap(x[l], x[r]);
        }
    }
    else {
        std::vector < int > res;
        int m = (l + r) / 2;
        MergeSort(x, l, m);
        MergeSort(x, m + 1, r);
        int c1 = l;
        int c2 = m + 1;
        while (c1 <= m && c2 <= r) {

            if (x[c1] < x[c2]) {
                res.push_back(x[c1]);
                c1++;
            }
            else {
                res.push_back(x[c2]);
                c2++;
            }
        }

        if (c1 <= m) {
            while (c1 <= m) {
                res.push_back(x[c1]);
                c1++;
            }
        }
        if (c2 <= r) {
            while (c2 <= r) {
                res.push_back(x[c2]);
                c2++;
            }
        }
        for (int i = l; i <= r; ++i) {
            x[i] = res[i - l];
        }
    }
}

int main()
{
    std::vector < int > a = { 5,4,3,2,1 };
    MergeSort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
