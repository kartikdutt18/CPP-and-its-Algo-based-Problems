#include <vector>
using namespace std;

int waterArea(vector<int> heights)
{
  if (heights.size() == 0)
    return 0;
  int totalWater = 0;
  int i = 0, j = heights.size() - 1;
  int leftMaxHeight = heights[i], rightMaxHeight = heights[j];
  while (i < j)
  {
    if (heights[i] < heights[j])
    {
      i++;
      leftMaxHeight = max(leftMaxHeight, heights[i]);
      totalWater += max(min(leftMaxHeight, rightMaxHeight) - heights[i], 0);
    }
    else
    {
      j--;
      rightMaxHeight = max(rightMaxHeight, heights[j]);
      totalWater += max(min(leftMaxHeight, rightMaxHeight) - heights[j], 0);
    }
  }

  return totalWater;
}
