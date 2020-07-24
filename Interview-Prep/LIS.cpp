#include <vector>
using namespace std;

int binarySearch(int startIdx, int endIdx, vector<int> indices,
                 vector<int> array, int num)
{
  if (startIdx > endIdx)
  {
    return startIdx;
  }
  int middleIdx = (startIdx + endIdx) / 2;
  if (array[indices[middleIdx]] < num)
  {
    startIdx = middleIdx + 1;
  }
  else
  {
    endIdx = middleIdx - 1;
  }
  return binarySearch(startIdx, endIdx, indices, array, num);
}

vector<int> longestIncreasingSubsequence(vector<int> array)
{
  vector<int> sequences(array.size(), 0);
  vector<int> indices(array.size() + 1, INT_MIN);
  int length = 0;
  for (int i = 0; i < array.size(); i++)
  {
    int num = array[i];
    int newLength = binarySearch(1, length, indices, array, num);
    sequences[i] = indices[newLength - 1];
    indices[newLength] = i;
    length = max(length, newLength);
  }

  vector<int> ans;
  int currentIdx = indices[length];
  while (currentIdx != INT_MIN)
  {
    ans.push_back(array[currentIdx]);
    currentIdx = sequences[currentIdx];
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
