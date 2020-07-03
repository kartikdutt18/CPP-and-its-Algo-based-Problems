#include <vector>
using namespace std;

int binarySearch(vector<int> &array, int target, bool upper = true)
{
  int low = 0, high = array.size() - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (array[mid] > target)
      low = mid + 1;
    else if (array[mid] < target)
      high = mid - 1;
    else
    {
      if (!upper)
      {
        if (mid == 0 || array[mid - 1] != target)
          return mid;
        else
          high = mid - 1;
      }
      else
      {
        if (mid == array.size() - 1 || array[mid + 1] != target)
          return mid;
        else
          low = mid + 1;
      }
    }
  }

  return -1;
}
vector<int> searchForRange(vector<int> array, int target)
{
  int t2 = binarySearch(array, target, true);
  int t1 = binarySearch(array, target, false);
  if (t2 < t1)
    return {-1, -1};
  return {t1, t2};
}
