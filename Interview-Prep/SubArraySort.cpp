#include <vector>
using namespace std;

vector<int> subarraySort(vector<int> array)
{
  bool isSorted = true;
  int minUnsortedElement = INT_MAX;
  int maxElement = INT_MIN;
  int lastIndex = 0;
  for (int i = 0; i < array.size(); i++)
  {
    bool isSortedElement = array[i] >= maxElement;
    isSorted = isSorted & isSortedElement;
    if (!isSortedElement)
    {
      minUnsortedElement = min(minUnsortedElement, array[i]);
      lastIndex = max(lastIndex, i);
    }
    maxElement = max(maxElement, array[i]);
  }
  if (isSorted)
  {
    return {-1, -1};
  }
  int startIndex = 0;
  for (int i = 0; i < array.size(); i++)
  {
    if (array[i] > minUnsortedElement)
    {
      startIndex = i;
      break;
    }
  }
  cout << startIndex << " , " << lastIndex << endl;
  return {startIndex, lastIndex};
}
