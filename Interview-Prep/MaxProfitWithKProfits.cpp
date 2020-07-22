#include <vector>
using namespace std;

int maxProfitWithKTransactions(vector<int> prices, int k)
{
  if (!prices.size())
    return 0;
  int n = prices.size();
  vector<vector<int>> dp(2, vector<int>(n + 1));
  for (int i = 1; i <= k; i++)
  {
    int maxSoFar = INT_MIN;
    for (int j = 1; j <= n; j++)
    {
      maxSoFar = max(maxSoFar, dp[0][j - 1] - prices[j - 1]);
      dp[1][j] = max({dp[1][j - 1], maxSoFar + prices[j - 1]});
    }

    swap(dp[1], dp[0]);
  }

  return dp[0][n];
}
