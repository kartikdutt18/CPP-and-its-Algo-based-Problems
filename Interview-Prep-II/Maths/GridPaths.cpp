#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int uniquePaths(int A, int B)
{
  vector<vector<int>> dp(A, vector<int>(B, 1));
  for (int i = 1; i < A; i++)
  {
    for (int j = 1; j < B; j++)
    {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[A - 1][B - 1];
}

int main()
{
  return 0;
}