#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void solve()
{
  int r, c;
  cin >> r >> c;
  vector<vector<char>> board(r, vector<char>(c, '.'));
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      cin >> board[i][j];
 
  vector<vector<int>> dp(r, vector<int>(c, 0));
  dp[0][0] = (board[0][0] != '#');
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (i == 0 && j == 0)
        dp[i][j] = (board[0][0] != '#');
      else if ((i == 0 || j == 0) && board[i][j] != '#')
        dp[i][j] = (i >= 1 ? dp[i - 1][j] : dp[i][j - 1]);
      else if (i != 0 && j != 0)
      {
        if (r - 1 >= 0 && board[i - 1][j] != '#')
          dp[i][j] = (dp[i][j]%MOD + dp[i - 1][j]%MOD)%MOD;
        if (c - 1 >= 0 && board[i][j - 1] != '#')
          dp[i][j] = (dp[i][j]%MOD + dp[i][j - 1]%MOD)%MOD;
      }
    }
  }
  cout << (dp[r - 1][c - 1]) << endl;
}

int main()
{
  solve();
  return 0;
}