#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum)
{
  vector<vector<int>> ans;
  sort(array.begin(), array.end());
  for (int i = 0; i < array.size(); i++)
  {
    for (int j = i + 1; j < array.size(); j++)
    {
      int left = j + 1;
      int right = array.size() - 1;
      while (left < right && (left < array.size()) && right < array.size())
      {
        int curSum = array[left] + array[right] + array[j] + array[i];
        if (curSum == targetSum)
        {
          ans.push_back({array[i], array[j], array[left], array[right]});
          left++;
          right--;
        }
        else if (curSum < targetSum)
        {
          left++;
        }
        else
        {
          right--;
        }
      }
    }
  }
  return ans;
}
