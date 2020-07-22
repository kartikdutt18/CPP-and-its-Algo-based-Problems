#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array)
{
  if (!array.size())
    return 0;
  if (array.size() == 1)
    return array[0];

  int firstSum = array[0];
  int secondSum = max(array[1], array[0]);
  int curSum = max(secondSum, firstSum);
  for (int i = 2; i < array.size(); i++)
  {
    curSum = max(secondSum, firstSum + array[i]);
    firstSum = secondSum;
    secondSum = curSum;
  }
  return curSum;
}
