#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n, k = 2;
  cin >> n >> k;
  vector<int> v(n), dp(n, INT_MAX);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  dp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    for (int j = i - 1; abs(i - j) <= k && j >= 0; j--)
    {
      if (j >= 0)
      {
        dp[i] = min(dp[j] + abs(v[i] - v[j]), dp[i]);
      }
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}