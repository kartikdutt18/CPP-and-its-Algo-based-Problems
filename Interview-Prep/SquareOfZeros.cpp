#include <vector>
using namespace std;

bool squareOfZeroes(vector<vector<int>> matrix)
{

  vector<vector<pair<int, int>>> dp(matrix.size(), vector<pair<int, int>>(matrix[0].size(), {0, 0}));

  // Fill the dp matrix.
  // Single Traversal ans.
  // Sqaure Matrix has to have size > 1.
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (j == 0)
        dp[i][j].first = matrix[i][j];
      else
        dp[i][j].first = dp[i][j - 1].first + matrix[i][j];

      if (i == 0)
        dp[i][j].second = matrix[i][j];
      else
        dp[i][j].second = matrix[i][j] + dp[i - 1][j].second;

      // Iterate over lengths.
      cout << "{" << dp[i][j].first << "," << dp[i][j].second << "}"
           << " ";
      for (int length = 1; length <= min(i, j); length++)
      {
        if (matrix[i - length][j] != 1 &&
            matrix[i - length][j - length] != 1 &&
            matrix[i][j - length] != 1 &&
            dp[i][j].first == dp[i][j - length].first &&
            dp[i - length][j].first == dp[i - length][j - length].first &&
            dp[i][j].second == dp[i - length][j].second &&
            dp[i][j - length].second == dp[i - length][j - length].second)

        {
          return true;
        }
      }
    }
    cout << endl;
  }

  return false;
}