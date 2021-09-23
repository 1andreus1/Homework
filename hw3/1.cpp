#include <iostream>


int fib(int n) {
    return n > 2 ? fib(n-1)+fib(n-2) : 1;
}

int main()
{
    std::cout << fib(5);
}