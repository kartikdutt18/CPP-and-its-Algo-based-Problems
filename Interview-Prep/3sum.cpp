#include <vector>
using namespace std;

#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum)
{
  sort(array.begin(), array.end());
  vector<vector<int>> ans;
  for (int i = 0; i < array.size(); i++)
  {
    int start = i + 1;
    int end = array.size() - 1;
    while (start < end)
    {
      int curSum = array[i] + array[start] + array[end];
      if (curSum == targetSum)
      {
        ans.push_back({array[i], array[start], array[end]});
        start++;
        end--;
      }
      else if (curSum < targetSum)
        start++;
      else
        end--;
    }
  }
  return ans;
}

int main()
{
  return 0;
}