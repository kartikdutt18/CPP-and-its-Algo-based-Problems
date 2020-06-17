#include <vector>

using namespace std;
void print(vector<int> array)
{
  for (int num : array)
    cout << num << " ";
  cout << endl;
}

bool isValid(int x, int y, int n, int m)
{
  return x >= 0 && y >= 0 && x < n && y < m;
}
vector<int> zigzagTraverse(vector<vector<int>> array)
{
  int i = 0, j = 0;
  int n = array.size(), m = array[0].size();
  bool goDown = true;
  vector<int> ans;
  int count = 0;
  while (isValid(i, j, n, m))
  {
    ans.push_back(array[i][j]);
    if (goDown)
    {
      if (i == n - 1 || j == 0)
      {
        goDown = false;
        if (i == n - 1)
        {
          j++;
        }
        if (j == 0)
        {
          i++;
        }
      }
      else
      {
        i++;
        j--;
      }
    }
    else
    {
      if (i == 0 || j == m - 1)
      {
        goDown = true;
        if (j == m - 1)
        {
          i++;
        }
        if (i == 0)
          j++;
      }
      else
      {
        i--;
        j++;
      }
    }
  }
  return ans;
}
