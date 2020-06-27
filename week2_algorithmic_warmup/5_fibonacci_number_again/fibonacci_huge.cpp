#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m)
{
    long long a = 1;
    long long b = 1, c;
    if (n == 0)
        return 0;
    else if (n <= 2)
        return a;
    else
    {
        long long i = 3;
        while (i <= n)
        {
            c = (a + b) % m;
            a = b;
            b = c;
            i++;
        }
    }
    return c;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
