#include <iostream>

int gcd_naive(int a, int b)
{
  int divisor = (a > b) ? b : a;
  int dividend = (a > b) ? a : b;
  int r = dividend % divisor;
  while (r != 0)
  {
    dividend = divisor;
    divisor = r;
    r = dividend % divisor;
    // std::cout << "*";
  }
  return divisor;
}

long long lcm_naive(int a, int b)
{
  long long prod = (long long)a * b;
  // std::cout << gcd_naive(a, b);
  // std::cout << "*";
  // std::cout << prod;

  long long lcm = prod / gcd_naive(a, b);

  return lcm;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
