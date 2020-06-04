#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b, ll c = 0, ll d = 0)
{
  if (c == 0 && d == 0)
    return a > b ? a : b;
  return max(a, max(b, max(c, d)));
}

int main()
{
  ll n, w;
  cin >> n >> w;
  vector<vector<ll>> dp(w + 1, vector<ll>(n + 1, 0));
  vector<ll> weights(n + 1, 0), value(n + 1, 0);
  for(int i = 1; i <= n; i++)
  {
    cin >> weights[i] >> value[i];
  }
  for (int i = 1; i <= w; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
      if (i - weights[j] >=0)
      {
        dp[i][j] = max(dp[i][j], value[j] +
            dp[i - weights[j]][j - 1]);
      }
    }
  }
  cout << dp[w][n] << endl;
  return 0;
}