#include <vector>
using namespace std;

vector<vector<int>> ans;
void permute(vector<int> &array, int start)
{
  ans.push_back(array);
  if (start >= array.size())
    return;
  for (int i = start; i < array.size(); i++)
  {
    for (int j = i + 1; j < array.size(); j++)
    {
      swap(array[i], array[j]);
      permute(array, i + 1);
      swap(array[i], array[j]);
    }
  }
  return;
}

vector<vector<int>> getPermutations(vector<int> array)
{
  if (array.empty())
    return {};
  ans.clear();
  permute(array, 0);
  return ans;
}
