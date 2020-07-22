#include <vector>
using namespace std;

vector<vector<int>> diskStacking(vector<vector<int>> disks)
{
  sort(disks.begin(), disks.end(), [](vector<int> &d1, vector<int> &d2) {
    return d1[2] < d2[2];
  });

  vector<int> dp(disks.size(), 0);
  for (int i = 0; i < dp.size(); i++)
  {
    dp[i] = disks[i][2];
  }

  vector<int> sequences(disks.size(), -1);
  int ansIdx = 0;
  for (int i = 1; i < disks.size(); i++)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (disks[i][0] > disks[j][0] && disks[i][1] > disks[j][1] &&
          disks[i][2] > disks[j][2] && dp[i] < dp[j] + disks[i][2])
      {
        dp[i] = dp[j] + disks[i][2];
        sequences[i] = j;
      }
    }

    if (dp[ansIdx] < dp[i])
      ansIdx = i;
  }

  vector<vector<int>> ans;
  while (ansIdx >= 0)
  {
    ans.push_back(disks[ansIdx]);
    ansIdx = sequences[ansIdx];
  }

  reverse(ans.begin(), ans.end());
  return ans;
}
