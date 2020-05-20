#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target)
{
  int low = 0;
  int high = arr.size() - 1;
  while (low <= high)
  {

    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return mid;
    if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
