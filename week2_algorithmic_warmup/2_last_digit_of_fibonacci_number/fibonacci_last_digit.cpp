#include <iostream>

long long int get_fibonacci_last_digit_naive(long long int n)
{
    if (n <= 1)
        return n;

    long long int previous = 0;
    long long int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        long long int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}

int main()
{
    long long int n;
    std::cin >> n;
    long long int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
}
