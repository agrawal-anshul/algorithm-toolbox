#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

using std::vector;

bool cmp(pair<double, int> x, pair<double, int> y)
{
  return x.first > y.first;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  int n = weights.size();
  // cout << n;
  vector<pair<double, int>> vw;
  for (int i = 0; i < n; i++)
  {

    double a = 1.0 * values[i] / weights[i];
    int b = weights[i];
    vw.push_back(make_pair(a, b));
    // cout << vw[i].first << " " << vw[i].second << " * ";
  }

  sort(vw.begin(), vw.end(), cmp);

  for (int i = 0; i < n && capacity != 0;)
  {
    int a = min(capacity, vw[i].second);
    capacity -= a;
    vw[i].second -= a;
    value += a * vw[i].first;
    if (vw[i].second == 0)
    {
      i++;
    }
  }

  // capacity:14  12  8   3   2   0
  //    value:6   26  44  59  62  64.6
  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout << fixed << setprecision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
