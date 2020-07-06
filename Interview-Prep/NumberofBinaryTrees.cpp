#include <bits/stdc++.h>
using namespace std;

int numberOfBinaryTreeTopologies(int n)
{
  if (n == 0)
    return 1;
  if (dp[n] != -1)
    return dp[n];
  int ans = 0;
  for (int leftTrees = 0; leftTrees < n; leftTrees++)
  {
    int rightTrees = n - leftTrees - 1;
    ans += numberOfBinaryTreeTopologies(leftTrees) * numberOfBinaryTreeTopologies(rightTrees);
  }
  return dp[n] = ans;
}

int numberOfBinaryTreeTopologiesIter(int n)
{
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  // O(n ** 2) / O(n)
  for (int i = 2; i <= n; i++)
  {
    for (int leftTrees = 0; leftTrees < i; leftTrees++)
    {
      int rightTrees = i - leftTrees - 1;
      dp[i] += dp[leftTrees] * dp[rightTrees];
    }
  }
  return dp[n];
}