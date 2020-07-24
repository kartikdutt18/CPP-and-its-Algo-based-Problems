#include <vector>
#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> onesInMat;
void dfs(pair<int, int> curPoint)
{
  if (!onesInMat.count(curPoint))
    return;
  onesInMat.erase(curPoint);
  vector<int> dx = {0, 0, -1, 1};
  vector<int> dy = {-1, 1, 0, 0};
  int x = curPoint.first;
  int y = curPoint.second;
  for (int i = 0; i < 4; i++)
  {
    if (onesInMat.count({x + dx[i], y + dy[i]}))
      dfs({x + dx[i], y + dy[i]});
  }
  return;
}
vector<int> riverSizes(vector<vector<int>> matrix)
{
  onesInMat.clear();
  vector<int> ans;
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (matrix[i][j])
        onesInMat.insert({i, j});
    }
  }

  while (!onesInMat.empty())
  {
    int curEl = onesInMat.size();
    dfs(*onesInMat.begin());
    int discoveredEl = curEl - onesInMat.size();
    ans.push_back(discoveredEl);
  }
  return ans;
}
