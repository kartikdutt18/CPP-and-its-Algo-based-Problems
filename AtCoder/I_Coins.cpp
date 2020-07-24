#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<vector<double>> dp(2, vector<double>(n + 1, 0));
  vector<double> probs(n + 1, 0);
  double ans = 0.0;
  for (int i = 1; i <= n; i++)
  {
    cin >> dp[0][i];
    probs[i] = dp[0][i];
  }

  for (int i = 2; i <= n; i++)
  {
    for (int j = i; j <= n; j++)
    {
      dp[1][j] = (dp[0][j - 1] * probs[j]) + dp[0][j] * (1 - probs[j]);
      cout << dp[1][j] << " ";
    }
    cout << endl;
    if (i > n / 2)
      ans += accumulate(dp[1].begin(), dp[1].end(), 0.0);
    swap(dp[1], dp[0]);
    fill(dp[1].begin(), dp[1].end(), 0);
  }
  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}