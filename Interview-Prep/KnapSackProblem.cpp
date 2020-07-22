#include <vector>
using namespace std;

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity)
{
  vector<vector<int>> dp(capacity + 1, vector<int>(items.size() + 1, 0));
  for (int i = 1; i <= capacity; i++)
  {
    for (int j = 1; j <= items.size(); j++)
    {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (i - items[j - 1][1] >= 0)
      {
        dp[i][j] = max(dp[i - items[j - 1][1]][j - 1] +
                           items[j - 1][0],
                       dp[i][j]);
      }
    }
  }

  vector<int> selectedItems;
  int i = capacity, j = items.size();
  while (i > 0 && j > 0)
  {
    if (dp[i][j] == dp[i - 1][j])
      i--;
    else if (dp[i][j] == dp[i][j - 1])
      j--;
    else
    {
      selectedItems.push_back(j - 1);
      i = i - items[j - 1][1];
      j--;
    }
  }
  reverse(selectedItems.begin(), selectedItems.end());
  return {
      {dp[capacity][items.size()]},
      selectedItems};
}
