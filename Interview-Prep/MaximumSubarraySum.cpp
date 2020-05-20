#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array)
{
  int curSum = 0;
  int maxSum = INT_MIN;
  for (int num : array)
  {
    curSum += num;
    maxSum = max(maxSum, curSum);
    if (curSum < 0)
      curSum = 0;
  }
  return maxSum;
}
