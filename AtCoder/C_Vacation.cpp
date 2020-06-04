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
  int n;
  cin >> n;
  vector<vector<ll>> board(n + 1, vector<ll>(3, 0)),
      dp(n + 1, vector<ll>(3, 0));
  for (int i = 1; i<=n; i++)
  {
    cin >> board[i][0] >> board[i][1] >> board[i][2];
  }

  // Intial Condition.
  dp[1] = board[1];
  // This code is for same activity for at max 2 days. 
  // Read the Question wrong.
  // Commenting this because this is a better question.
  // Same activity for atmax k days =>
  // dp[i][j] = max(dp[i][j - k] + sum(board(i , i, j -k, j)), dp[i][j-1]....)
  /*
  for (int i = 2; i <= n; i++)
  {
    dp[i][0] = board[i][0] + max(dp[i - 1][1], dp[i - 1][2],
        board[i - 1][0] + dp[i - 2][1], board[i - 1][0] + dp[i - 2][2]);
    dp[i][1] = board[i][1] + max(dp[i - 1][0], dp[i - 1][2],
        board[i - 1][1] + dp[i - 2][2], board[i - 1][1] + dp[i - 2][0]);
    dp[i][2] = board[i][2] + max(dp[i - 1][0], dp[i - 1][1],
        board[i - 1][2] + dp[i - 2][0], board[i - 1][2] + dp[i - 2][1]);
  }
  */
 for (int i = 2; i <= n; i++)
  {
    dp[i][0] = board[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = board[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = board[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
  }
  cout << max(dp[n][0], dp[n][1], dp[n][2]) << endl;
  return 0;
}